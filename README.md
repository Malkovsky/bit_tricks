# Bit tricks















Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.















# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|45524.10 ms|45522.30 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|27579.00 ms|27577.80 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6770.21 ms|6769.89 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4029.38 ms|4029.21 ms|1|
|"All 32-bit uint/Count bits set with builtin"|13349.70 ms|13349.20 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|69577.00 ms|69573.00 ms|1|
|"All 32-bit uint/Reverse parallel"|6011.60 ms|6011.36 ms|1|
|"All 32-bit uint/Reverse lookup"|4011.42 ms|4011.27 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|8310.24 ms|8309.91 ms|1|
|"All 24-bit uint/Select parallel"|972.69 ms|972.66 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|2763.23 ms|2763.12 ms|1|
|"All 32-bit uint/LSB parallel"|7653.95 ms|7653.71 ms|1|
|"All 32-bit uint/LSB float"|2766.64 ms|2766.55 ms|1|
|"All 32-bit uint/LSB lookup"|2767.08 ms|2766.99 ms|1|
|"All 32-bit uint/LSB mod lookup"|5015.21 ms|5013.58 ms|1|
|"All 32-bit uint/LSB De Bruijn"|1338.04 ms|1338.01 ms|1|
|"All 32-bit uint/LSB builtin ctz"|1337.08 ms|1337.03 ms|1|
|"All 32-bit single bit uint/LSB naive"|179.18 ns|179.17 ns|3893997|
|"All 32-bit single bituint/LSB parallel"|45.04 ns|45.03 ns|15452914|
|"All 32-bit single bituint/LSB float"|30.77 ns|30.76 ns|22331270|
|"All 32-bit single bit uint/LSB lookup"|29.59 ns|29.59 ns|23498091|
|"All 32-bit single bituint/LSB mod lookup"|40.97 ns|40.97 ns|17077605|
|"All 32-bit single bituint/LSB De Bruijn"|20.29 ns|20.29 ns|34526862|
|"All 32-bit single bituint/LSB builtin ctz"|20.28 ns|20.28 ns|34507293|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|969.46 ms|969.42 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1161.31 ms|1161.27 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1876.32 ms|1876.25 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3278.17 ms|3278.01 ms|1|
