# Bit tricks































































Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.































































# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|46854.50 ms|46852.80 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|1335.16 ms|1335.10 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6513.73 ms|6513.47 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4029.74 ms|4029.57 ms|1|
|"All 32-bit uint/Count bits set with builtin"|1336.03 ms|1335.97 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|69520.30 ms|69518.00 ms|1|
|"All 32-bit uint/Reverse parallel"|6229.46 ms|6229.25 ms|1|
|"All 32-bit uint/Reverse lookup"|4018.38 ms|4018.33 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|8136.61 ms|8136.47 ms|1|
|"All 24-bit uint/Select parallel"|1999.64 ms|1999.60 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|2567.54 ms|2567.51 ms|1|
|"All 32-bit uint/LSB parallel"|7366.21 ms|7366.11 ms|1|
|"All 32-bit uint/LSB float"|2954.07 ms|2954.03 ms|1|
|"All 32-bit uint/LSB lookup"|2761.19 ms|2761.14 ms|1|
|"All 32-bit uint/LSB mod lookup"|8002.13 ms|8002.01 ms|1|
|"All 32-bit uint/LSB De Bruijn"|1345.63 ms|1345.61 ms|1|
|"All 32-bit uint/LSB builtin ctz"|1338.26 ms|1338.23 ms|1|
|"All 32-bit single bit uint/LSB naive"|175.61 ns|175.61 ns|3998695|
|"All 32-bit single bituint/LSB parallel"|49.26 ns|49.26 ns|14127259|
|"All 32-bit single bituint/LSB float"|27.26 ns|27.26 ns|25716520|
|"All 32-bit single bit uint/LSB lookup"|31.52 ns|31.52 ns|22298392|
|"All 32-bit single bituint/LSB mod lookup"|57.77 ns|57.77 ns|12121144|
|"All 32-bit single bituint/LSB De Bruijn"|17.41 ns|17.41 ns|40198935|
|"All 32-bit single bituint/LSB builtin ctz"|17.48 ns|17.48 ns|40201840|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|969.10 ms|969.07 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1145.07 ms|1145.06 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1453.99 ms|1453.97 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3260.63 ms|3260.59 ms|1|
