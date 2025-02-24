#include "bits.hpp"
#include <benchmark/benchmark.h>


using namespace bits;

#define All32Uints(method)                                                     \
  static void BM##method(benchmark::State &state) {                            \
    for (auto _ : state) {                                                     \
      for (uint32_t x = 1; x != 0; ++x) {                                      \
        benchmark::DoNotOptimize(method(x));                                   \
      }                                                                        \
    }                                                                          \
  }

#define All24UintsIteratePosition(method)                                      \
  static void BM##method(benchmark::State &state) {                            \
    for (auto _ : state) {                                                     \
      for (uint32_t x = 0; x != (1 << 24); ++x) {                              \
        for (size_t i = 1; i < 32; ++i) {                                      \
          benchmark::DoNotOptimize(method(x, i));                              \
        }                                                                      \
      }                                                                        \
    }                                                                          \
  }

#define All32SingleBitSet(method)                                              \
  static void BM_SB##method(benchmark::State &state) {                         \
    for (auto _ : state) {                                                     \
      for (size_t x = 0; x < 32; ++x) {                                        \
        benchmark::DoNotOptimize(method(1 << x));                              \
      }                                                                        \
    }                                                                          \
  }

All32Uints(_count_bits_set_naive);
All32Uints(_count_bits_set_iterate_set_bits);
All32Uints(_count_bits_set_parallel);
All32Uints(_count_bits_set_lookup);

All32Uints(_reverse_naive);
All32Uints(_reverse_parallel);
All32Uints(_reverse_lookup);

All24UintsIteratePosition(_select_naive);
All24UintsIteratePosition(_select_parallel);

All32Uints(_least_significant_bit_naive);
All32Uints(_least_significant_bit_binary_search);
All32Uints(_least_significant_bit_via_float);
All32Uints(_least_significant_bit_lookup);
All32Uints(_least_significant_bit_mod_lookup);
All32Uints(_least_significant_bit_de_bruijn);

All32SingleBitSet(_least_significant_bit_naive);
All32SingleBitSet(_least_significant_bit_binary_search);
All32SingleBitSet(_least_significant_bit_via_float);
All32SingleBitSet(_least_significant_bit_lookup);
All32SingleBitSet(_least_significant_bit_mod_lookup);
All32SingleBitSet(_least_significant_bit_de_bruijn);

All24UintsIteratePosition(_mod_by_power_of_two_minus_one_naive);
All24UintsIteratePosition(_mod_by_power_of_two_minus_one_no_division_v1);
All24UintsIteratePosition(_mod_by_power_of_two_minus_one_no_division_v2);
All24UintsIteratePosition(_mod_by_power_of_two_minus_one_lookup);

/**
 * Count bits set
 */

BENCHMARK(BM_count_bits_set_naive)
    ->Name("All 32-bit uint/Count bits set naive")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_count_bits_set_iterate_set_bits)
    ->Name("All 32-bit uint/Count bits set iterate set bits")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_count_bits_set_parallel)
    ->Name("All 32-bit uint/Count bits set in parallel")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_count_bits_set_lookup)
    ->Name("All 32-bit uint/Count bits set with lookup table")
    ->Unit(benchmark::kMillisecond);

/**
 * Reverse bits
 */

BENCHMARK(BM_reverse_naive)
    ->Name("All 32-bit uint/Reverse naive")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_reverse_parallel)
    ->Name("All 32-bit uint/Reverse parallel")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_reverse_lookup)
    ->Name("All 32-bit uint/Reverse lookup")
    ->Unit(benchmark::kMillisecond);


/**
 * Select
 */

BENCHMARK(BM_select_naive)
    ->Name("All 24-bit uint/Select naive")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_select_parallel)
    ->Name("All 24-bit uint/Select parallel")
    ->Unit(benchmark::kMillisecond);

/**
 * Least significant bit
 */

BENCHMARK(BM_least_significant_bit_naive)
    ->Name("All 32-bit uint/LSB naive")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_least_significant_bit_binary_search)
    ->Name("All 32-bit uint/LSB parallel")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_least_significant_bit_via_float)
    ->Name("All 32-bit uint/LSB float")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_least_significant_bit_lookup)
    ->Name("All 32-bit uint/LSB lookup")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_least_significant_bit_mod_lookup)
    ->Name("All 32-bit uint/LSB mod lookup")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_least_significant_bit_de_bruijn)
    ->Name("All 32-bit uint/LSB De Bruijn")
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_SB_least_significant_bit_naive)
    ->Name("All 32-bit single bit uint/LSB naive");
BENCHMARK(BM_SB_least_significant_bit_binary_search)
    ->Name("All 32-bit single bituint/LSB parallel");
BENCHMARK(BM_SB_least_significant_bit_via_float)
    ->Name("All 32-bit single bituint/LSB float");
BENCHMARK(BM_SB_least_significant_bit_lookup)
    ->Name("All 32-bit single bit uint/LSB lookup");
BENCHMARK(BM_SB_least_significant_bit_mod_lookup)
    ->Name("All 32-bit single bituint/LSB mod lookup");
BENCHMARK(BM_SB_least_significant_bit_de_bruijn)
    ->Name("All 32-bit single bituint/LSB De Bruijn");

  
/**
 * Division by 2^k-1
 */

BENCHMARK(BM_mod_by_power_of_two_minus_one_naive)
    ->Name("All 24-bit uint/Division by 2^k-1 naive")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_mod_by_power_of_two_minus_one_no_division_v1)
    ->Name("All 24-bit uint/Division by 2^k-1 cycle v1")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_mod_by_power_of_two_minus_one_no_division_v2)
    ->Name("All 24-bit uint/Division by 2^k-1 cycle v2")
    ->Unit(benchmark::kMillisecond);
BENCHMARK(BM_mod_by_power_of_two_minus_one_lookup)
    ->Name("All 24-bit uint/Division by 2^k-1 lookup")
    ->Unit(benchmark::kMillisecond);