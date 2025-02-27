# Bit tricks































Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.































# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|46860.50 ms|46859.50 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|1334.63 ms|1334.57 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6535.01 ms|6533.59 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4033.26 ms|4033.07 ms|1|
|"All 32-bit uint/Count bits set with builtin"|1342.07 ms|1342.00 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|69534.30 ms|69533.10 ms|1|
|"All 32-bit uint/Reverse parallel"|6233.76 ms|6233.70 ms|1|
|"All 32-bit uint/Reverse lookup"|4019.28 ms|4019.23 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|8078.90 ms|8078.82 ms|1|
|"All 24-bit uint/Select parallel"|1996.78 ms|1996.76 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|2576.80 ms|2576.79 ms|1|
|"All 32-bit uint/LSB parallel"|7461.68 ms|7461.58 ms|1|
|"All 32-bit uint/LSB float"|2954.00 ms|2953.98 ms|1|
|"All 32-bit uint/LSB lookup"|2758.81 ms|2758.78 ms|1|
|"All 32-bit uint/LSB mod lookup"|8004.04 ms|8003.94 ms|1|
|"All 32-bit uint/LSB De Bruijn"|1341.49 ms|1341.47 ms|1|
|"All 32-bit uint/LSB builtin ctz"|1336.37 ms|1336.33 ms|1|
|"All 32-bit single bit uint/LSB naive"|175.32 ns|175.30 ns|3996616|
|"All 32-bit single bituint/LSB parallel"|49.24 ns|49.24 ns|14222204|
|"All 32-bit single bituint/LSB float"|27.18 ns|27.18 ns|25768983|
|"All 32-bit single bit uint/LSB lookup"|31.05 ns|31.05 ns|22598665|
|"All 32-bit single bituint/LSB mod lookup"|57.80 ns|57.79 ns|12117576|
|"All 32-bit single bituint/LSB De Bruijn"|17.42 ns|17.42 ns|40212206|
|"All 32-bit single bituint/LSB builtin ctz"|17.42 ns|17.42 ns|40225495|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|969.43 ms|969.38 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1162.99 ms|1162.90 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1454.18 ms|1454.13 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3260.53 ms|3260.36 ms|1|
