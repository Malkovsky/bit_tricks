#include <stdint.h>

#ifdef __BMI2__
#include <immintrin.h>
#endif
#ifdef __SSE4_2__
#include <xmmintrin.h>
#endif

#ifdef WIN32
#include "iso646.h"
#endif

#include <iostream>

namespace bits {

void print_binary32(uint32_t x) {
  for (int i = 31; i >= 0; --i) {
    std::cout << (x & (1 << i) ? 1 : 0);
    if (i % 8 == 0) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

/**
 * Alternatively can be initialized as
 *  BitsSetTable256[0] = 0;
 *  for (int i = 0; i < 256; i++)
 *  {
 *      BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
 *  }
 *
 */
static const uint8_t BitsSetTable256[256] = {
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
    B6(0), B6(1), B6(1), B6(2)};

static const uint32_t BitSetParallelMasks[] = {
    0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

static const uint8_t BitReverseTable256[256] = {
#define R2(n) n, n + 2 * 64, n + 1 * 64, n + 3 * 64
#define R4(n) R2(n), R2(n + 2 * 16), R2(n + 1 * 16), R2(n + 3 * 16)
#define R6(n) R4(n), R4(n + 2 * 4), R4(n + 1 * 4), R4(n + 3 * 4)
    R6(0), R6(2), R6(1), R6(3)};

static const uint8_t LeastSignificantBitTable256[256] = {
#define LSBT0 0, 1, 0
#define LSBT1 LSBT0, 2, LSBT0
#define LSBT2 LSBT1, 3, LSBT1
#define LSBT3 LSBT2, 4, LSBT2
#define LSBT4 LSBT3, 5, LSBT3
#define LSBT5 LSBT4, 6, LSBT4
    0, LSBT5, 7, LSBT5};

static const uint8_t LeastSignificantBitMod37[] = {
    32, 0,  1,  26, 2,  23, 27, 0,  3, 16, 24, 30, 28, 11, 0,  13, 4,  7, 17,
    0,  25, 22, 31, 15, 29, 10, 12, 6, 0,  21, 14, 9,  5,  20, 8,  19, 18};

static const uint8_t LeastSignificantBitDeBruijn[] = {
    0,  1,  28, 2,  29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4,  8,
    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6,  11, 5,  10, 9};

static const unsigned int DivisionM[] = {
    0x00000000, 0x55555555, 0x33333333, 0xc71c71c7, 0x0f0f0f0f, 0xc1f07c1f,
    0x3f03f03f, 0xf01fc07f, 0x00ff00ff, 0x07fc01ff, 0x3ff003ff, 0xffc007ff,
    0xff000fff, 0xfc001fff, 0xf0003fff, 0xc0007fff, 0x0000ffff, 0x0001ffff,
    0x0003ffff, 0x0007ffff, 0x000fffff, 0x001fffff, 0x003fffff, 0x007fffff,
    0x00ffffff, 0x01ffffff, 0x03ffffff, 0x07ffffff, 0x0fffffff, 0x1fffffff,
    0x3fffffff, 0x7fffffff};

static const unsigned int DivisionQ[][6] = {
    {0, 0, 0, 0, 0, 0},       {16, 8, 4, 2, 1, 1},
    {16, 8, 4, 2, 2, 2},      {15, 6, 3, 3, 3, 3},
    {16, 8, 4, 4, 4, 4},      {15, 5, 5, 5, 5, 5},
    {12, 6, 6, 6, 6, 6},      {14, 7, 7, 7, 7, 7},
    {16, 8, 8, 8, 8, 8},      {9, 9, 9, 9, 9, 9},
    {10, 10, 10, 10, 10, 10}, {11, 11, 11, 11, 11, 11},
    {12, 12, 12, 12, 12, 12}, {13, 13, 13, 13, 13, 13},
    {14, 14, 14, 14, 14, 14}, {15, 15, 15, 15, 15, 15},
    {16, 16, 16, 16, 16, 16}, {17, 17, 17, 17, 17, 17},
    {18, 18, 18, 18, 18, 18}, {19, 19, 19, 19, 19, 19},
    {20, 20, 20, 20, 20, 20}, {21, 21, 21, 21, 21, 21},
    {22, 22, 22, 22, 22, 22}, {23, 23, 23, 23, 23, 23},
    {24, 24, 24, 24, 24, 24}, {25, 25, 25, 25, 25, 25},
    {26, 26, 26, 26, 26, 26}, {27, 27, 27, 27, 27, 27},
    {28, 28, 28, 28, 28, 28}, {29, 29, 29, 29, 29, 29},
    {30, 30, 30, 30, 30, 30}, {31, 31, 31, 31, 31, 31}};

static const unsigned int DivisionR[][6] = {
    {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x0000ffff, 0x000000ff, 0x0000000f, 0x00000003, 0x00000001, 0x00000001},
    {0x0000ffff, 0x000000ff, 0x0000000f, 0x00000003, 0x00000003, 0x00000003},
    {0x00007fff, 0x0000003f, 0x00000007, 0x00000007, 0x00000007, 0x00000007},
    {0x0000ffff, 0x000000ff, 0x0000000f, 0x0000000f, 0x0000000f, 0x0000000f},
    {0x00007fff, 0x0000001f, 0x0000001f, 0x0000001f, 0x0000001f, 0x0000001f},
    {0x00000fff, 0x0000003f, 0x0000003f, 0x0000003f, 0x0000003f, 0x0000003f},
    {0x00003fff, 0x0000007f, 0x0000007f, 0x0000007f, 0x0000007f, 0x0000007f},
    {0x0000ffff, 0x000000ff, 0x000000ff, 0x000000ff, 0x000000ff, 0x000000ff},
    {0x000001ff, 0x000001ff, 0x000001ff, 0x000001ff, 0x000001ff, 0x000001ff},
    {0x000003ff, 0x000003ff, 0x000003ff, 0x000003ff, 0x000003ff, 0x000003ff},
    {0x000007ff, 0x000007ff, 0x000007ff, 0x000007ff, 0x000007ff, 0x000007ff},
    {0x00000fff, 0x00000fff, 0x00000fff, 0x00000fff, 0x00000fff, 0x00000fff},
    {0x00001fff, 0x00001fff, 0x00001fff, 0x00001fff, 0x00001fff, 0x00001fff},
    {0x00003fff, 0x00003fff, 0x00003fff, 0x00003fff, 0x00003fff, 0x00003fff},
    {0x00007fff, 0x00007fff, 0x00007fff, 0x00007fff, 0x00007fff, 0x00007fff},
    {0x0000ffff, 0x0000ffff, 0x0000ffff, 0x0000ffff, 0x0000ffff, 0x0000ffff},
    {0x0001ffff, 0x0001ffff, 0x0001ffff, 0x0001ffff, 0x0001ffff, 0x0001ffff},
    {0x0003ffff, 0x0003ffff, 0x0003ffff, 0x0003ffff, 0x0003ffff, 0x0003ffff},
    {0x0007ffff, 0x0007ffff, 0x0007ffff, 0x0007ffff, 0x0007ffff, 0x0007ffff},
    {0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff},
    {0x001fffff, 0x001fffff, 0x001fffff, 0x001fffff, 0x001fffff, 0x001fffff},
    {0x003fffff, 0x003fffff, 0x003fffff, 0x003fffff, 0x003fffff, 0x003fffff},
    {0x007fffff, 0x007fffff, 0x007fffff, 0x007fffff, 0x007fffff, 0x007fffff},
    {0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff},
    {0x01ffffff, 0x01ffffff, 0x01ffffff, 0x01ffffff, 0x01ffffff, 0x01ffffff},
    {0x03ffffff, 0x03ffffff, 0x03ffffff, 0x03ffffff, 0x03ffffff, 0x03ffffff},
    {0x07ffffff, 0x07ffffff, 0x07ffffff, 0x07ffffff, 0x07ffffff, 0x07ffffff},
    {0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff},
    {0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff, 0x1fffffff},
    {0x3fffffff, 0x3fffffff, 0x3fffffff, 0x3fffffff, 0x3fffffff, 0x3fffffff},
    {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff}};


/**
 * reverses the bits in a obvious way: popping bit by bit and appending them in
 * reverse order
 */
uint32_t _reverse_naive(uint32_t x) {
  uint32_t result = 0;
  for (size_t i = 0; i < 32; ++i) {
    result = (result << 1) | (x & 1);
    x >>= 1;
  }
  return result;
}

/**
 * Reverses bits in the 32-bit integer in 5 operations. i-th operation
 * swaps bits in two halfs of every 2^i bit block.
 *
 * Note: the code to generate j-th masks
 * uint32_t x = 0, y;
 * for (int i = 0; i < 32; ++i) {
 *     x |= (1 << i) * (((i / (1 << j)) & 1) == 0);
 * }
 * y = ~x;
 */
uint32_t _reverse_parallel(uint32_t x) {
  x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
  x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
  x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
  x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
  x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
  return x;
}

/**
 * Reverses the bits of 32-but uint using byte lookup table
 */
uint32_t _reverse_lookup(uint32_t x) {
  return (BitReverseTable256[x & 0xff] << 24) |
         (BitReverseTable256[(x >> 8) & 0xff] << 16) |
         (BitReverseTable256[(x >> 16) & 0xff] << 8) |
         (BitReverseTable256[(x >> 24) & 0xff]);
}

/**
 * counts the number of '1' bits in a naive way: tear of bit by bit
 * while x != 0, the same way one would calculate sum of digits.
 */
size_t _count_bits_set_naive(uint32_t x) {
  size_t result = 0;
  while (x > 0) {
    result += x & 1;
    x >>= 1;
  }
  return result;
}

/**
 * Counts the number of '1' bits by iterating over them.
 */
size_t _count_bits_set_iterate_set_bits(uint32_t x) {
  size_t result = 0;
  while (x > 0) {
    ++result;
    x = x & (x - 1);
  }
  return result;
}

/**
 * Count the number of '1' bits in the x using byte lookup table
 */
size_t _count_bits_set_lookup(uint32_t x) {
  return BitsSetTable256[x & 0xff] + BitsSetTable256[(x >> 8) & 0xff] +
         BitsSetTable256[(x >> 16) & 0xff] + BitsSetTable256[x >> 24];
}

size_t _count_bits_set_parallel(uint32_t x) {
  uint32_t c = x - ((x >> 1) & BitSetParallelMasks[0]);
  c = ((c >> 2) & BitSetParallelMasks[1]) + (c & BitSetParallelMasks[1]);
  c = ((c >> 4) + c) & BitSetParallelMasks[2];
  c = ((c >> 8) + c) & BitSetParallelMasks[3];
  c = ((c >> 16) + c) & BitSetParallelMasks[4];
  return c;
}

/**
 * finds number of '1' bits of x before position first_bits
 * aka rank
 */
size_t _count_prefix_bits_set(uint32_t x, size_t first_bits) {
  uint32_t mask = (first_bits > 0) * (1 + (((1 << (first_bits - 1)) - 1) << 1));
  return _count_bits_set_lookup(x & mask);
}

/**
 * finds the position of the rank-th '1' bit
 * aka select
 */
size_t _select_naive(uint32_t x, size_t rank) {
  if (rank == 0) {
    return 32;
  }
  size_t result = 0;
  while (x > 0 && rank > 0) {
    if (x & 1)
      --rank;
    x >>= 1;
    ++result;
  }
  if (x == 0 && rank > 0) {
    return 32;
  }
  return result - 1;
}

size_t _select_parallel(uint32_t x, size_t rank) {
  // parallel rank
  uint32_t s1 =
      ((x >> 1) & BitSetParallelMasks[0]) + (x & BitSetParallelMasks[0]);
  uint32_t s2 =
      ((s1 >> 2) & BitSetParallelMasks[1]) + (s1 & BitSetParallelMasks[1]);
  uint32_t s3 =
      ((s2 >> 4) & BitSetParallelMasks[2]) + (s2 & BitSetParallelMasks[2]);
  uint32_t s4 =
      ((s3 >> 8) & BitSetParallelMasks[3]) + (s3 & BitSetParallelMasks[3]);
  uint32_t s5 =
      ((s4 >> 16) & BitSetParallelMasks[4]) + (s4 & BitSetParallelMasks[4]);

  // the next code selects rank most significant bit with 0-based indexing
  // redefine rank to find least significant bit.
  if (rank > s5) {
    return 32;
  }
  rank = s5 - rank + 1;
  // parallel binary search
  size_t t = (s4 >> 16);
  size_t s = 32;
  if (rank > t) {
    s -= 16;
    rank -= t;
  }
  t = (s3 >> (s - 8)) & 0xf;
  if (rank > t) {
    s -= 8;
    rank -= t;
  }
  t = (s2 >> (s - 4)) & 0x7;
  if (rank > t) {
    s -= 4;
    rank -= t;
  }
  t = (s1 >> (s - 2)) & 0x3;
  if (rank > t) {
    s -= 2;
    rank -= t;
  }
  t = (x >> (s - 1)) & 0x1;
  if (rank > t)
    s--;
  return s - 1;
}

size_t _least_significant_bit_naive(uint32_t x) {
  for (size_t i = 0; i < 32; ++i) {
    if (x & (1 << i)) {
      return i;
    }
  }
  return 0;
}

size_t _least_significant_bit_binary_search(uint32_t x) {
  size_t result = 1;
  if ((x & 0xFFFF) == 0) {
    x >>= 16;
    result += 16;
  }
  if ((x & 0xFF) == 0) {
    x >>= 8;
    result += 8;
  }
  if ((x & 0xF) == 0) {
    x >>= 4;
    result += 4;
  }
  if ((x & 0x3) == 0) {
    x >>= 2;
    result += 2;
  }
  result -= x & 0x1;
  return result;
}

size_t _least_significant_bit_parallel(uint32_t x) {
  size_t result = 31;
  x ^= x & (x - 1);
  if (x & 0x0000FFFF)
    result -= 16;
  if (x & 0x00FF00FF)
    result -= 8;
  if (x & 0x0F0F0F0F)
    result -= 4;
  if (x & 0x33333333)
    result -= 2;
  if (x & 0x55555555)
    result -= 1;
  return result;
}

size_t _least_significant_bit_via_float(uint32_t x) {
  float y = x & ~(x - 1);
  return (*(uint32_t *)&y >> 23) - 0x7F;
}

size_t _least_significant_bit_lookup(uint32_t x) {
  size_t result = 0;
  if (x & 0xFF)
    return result + LeastSignificantBitTable256[x & 0xFF];
  x >>= 8;
  result += 8;
  if (x & 0xFF)
    return result + LeastSignificantBitTable256[x & 0xFF];
  x >>= 8;
  result += 8;
  if (x & 0xFF)
    return result + LeastSignificantBitTable256[x & 0xFF];
  x >>= 8;
  result += 8;
  if (x)
    return result + LeastSignificantBitTable256[x];
  return 32;
}

size_t _least_significant_bit_mod_lookup(uint32_t x) {
  return LeastSignificantBitMod37[(x & ~(x - 1)) % 37];
}

size_t _least_significant_bit_de_bruijn(uint32_t x) {
  return LeastSignificantBitDeBruijn[((x & ~(x - 1)) * 0x077CB531U) >> 27];
}

uint32_t _mod_by_power_of_two_minus_one_naive(uint32_t x, size_t k) {
  return x % ((1 << k) - 1);
}

uint32_t _mod_by_power_of_two_minus_one_no_division_v1(uint32_t x, size_t k) {
  uint32_t m = (1 << k) - 1;
  while (x >= m) {
    x -= m;
    x = (x >> k) + (x & m);
  }
  return x;
}

uint32_t _mod_by_power_of_two_minus_one_no_division_v2(uint32_t x, size_t k) {
  uint32_t result = x, d = (1 << k) - 1;
  for (; x > d; x = result) {
    for (result = 0; x; x >>= k) {
      result += x & d;
    }
  }
  return result == d ? 0 : result;
}

uint32_t _mod_by_power_of_two_minus_one_lookup(uint32_t x, size_t k) {
  uint32_t result = (x & DivisionM[k]) + ((x >> k) & DivisionM[k]);
  uint32_t d = (1 << k) - 1;

  for (const uint32_t * q = &DivisionQ[k][0], * r = &DivisionR[k][0]; result > d; q++, r++)
  {
    result = (result >> *q) + (result & *r);
  }
  return result == d ? 0 : result;
}

} // namespace bits