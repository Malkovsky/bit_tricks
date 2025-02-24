#include "gtest/gtest.h"

#include "bits.hpp"

namespace {

TEST(ReverseBits, All32Ints) {
  for (uint32_t x = 1; x != 0; ++x) {
    auto naive = bits::_reverse_naive(x);
    auto parallel = bits::_reverse_parallel(x);
    auto lookup = bits::_reverse_lookup(x);
    EXPECT_EQ(naive, parallel);
    EXPECT_EQ(naive, lookup);
  }
}

TEST(CountBitsSet, All32Ints) {
  for (uint32_t x = 1; x != 0; ++x) {
    auto naive = bits::_count_bits_set_naive(x);
    auto iterate = bits::_count_bits_set_iterate_set_bits(x);
    auto parallel = bits::_count_bits_set_parallel(x);
    auto lookup = bits::_count_bits_set_lookup(x);
    EXPECT_EQ(naive, parallel);
    EXPECT_EQ(naive, lookup);
    EXPECT_EQ(naive, iterate);
  }
}

TEST(LeastSignificantBit, All32Ints) {
  for (uint32_t x = 1; x != 0; ++x) {
    auto naive = bits::_least_significant_bit_naive(x);
    auto bs = bits::_least_significant_bit_binary_search(x);
    auto from_float = bits::_least_significant_bit_via_float(x);
    auto parallel = bits::_least_significant_bit_parallel(x);
    auto lookup = bits::_least_significant_bit_lookup(x);
    auto mod_lookup = bits::_least_significant_bit_mod_lookup(x);
    auto de_bruijn = bits::_least_significant_bit_de_bruijn(x);
    EXPECT_EQ(naive, bs);
    EXPECT_EQ(naive, from_float);
    EXPECT_EQ(naive, parallel);
    EXPECT_EQ(naive, lookup);
    EXPECT_EQ(naive, mod_lookup);
    EXPECT_EQ(naive, de_bruijn);
  }
}

TEST(Select, Base) {
  EXPECT_EQ(bits::_select_parallel((255 + 255 * 256) * (1 + 256 * 256), 32),
            31);
  EXPECT_EQ(bits::_select_parallel(255, 1), 0);
  EXPECT_EQ(bits::_select_parallel(255, 2), 1);
  EXPECT_EQ(bits::_select_parallel(255, 3), 2);
  EXPECT_EQ(bits::_select_parallel(255, 4), 3);
  EXPECT_EQ(bits::_select_parallel(255, 5), 4);

  for (uint32_t x = 1; x < (1 << 24); ++x) {
    for (size_t i = 1; i <= 32; ++i) {
      EXPECT_EQ(bits::_select_naive(x, i), bits::_select_parallel(x, i));
    }
  }
}

TEST(PowerOfTwoMinusOneDivision, Base) {
  for (uint32_t x = 1; x != (1 << 24); ++x) {
    for (size_t k = 1; k < 24; ++k) {
      auto naive = bits::_mod_by_power_of_two_minus_one_naive(x, k);
      auto no_division_v1 = bits::_mod_by_power_of_two_minus_one_no_division_v1(x, k);
      auto no_division_v2 = bits::_mod_by_power_of_two_minus_one_no_division_v2(x, k);
      auto lookup = bits::_mod_by_power_of_two_minus_one_lookup(x, k);
      EXPECT_EQ(naive, no_division_v1);
      EXPECT_EQ(naive, no_division_v2);
      EXPECT_EQ(naive, lookup);
    }
  }
}

} // namespace