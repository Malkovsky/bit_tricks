# Bit tricks







Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.







# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|45466.40 ms|45464.90 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|47444.00 ms|47440.80 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6510.08 ms|6509.82 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4023.89 ms|4023.74 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|69630.70 ms|69627.50 ms|1|
|"All 32-bit uint/Reverse parallel"|6013.49 ms|6013.20 ms|1|
|"All 32-bit uint/Reverse lookup"|4015.04 ms|4014.84 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|8296.28 ms|8296.00 ms|1|
|"All 24-bit uint/Select parallel"|974.96 ms|974.92 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|3292.83 ms|3292.69 ms|1|
|"All 32-bit uint/LSB parallel"|7711.44 ms|7711.14 ms|1|
|"All 32-bit uint/LSB float"|2763.23 ms|2763.10 ms|1|
|"All 32-bit uint/LSB lookup"|2764.14 ms|2764.01 ms|1|
|"All 32-bit uint/LSB mod lookup"|4972.73 ms|4972.48 ms|1|
|"All 32-bit uint/LSB De Bruijn"|1336.53 ms|1336.49 ms|1|
|"All 32-bit single bit uint/LSB naive"|178.44 ns|178.44 ns|3923592|
|"All 32-bit single bituint/LSB parallel"|45.30 ns|45.30 ns|15432712|
|"All 32-bit single bituint/LSB float"|31.44 ns|31.44 ns|22224249|
|"All 32-bit single bit uint/LSB lookup"|29.69 ns|29.69 ns|23470173|
|"All 32-bit single bituint/LSB mod lookup"|41.07 ns|41.07 ns|17085242|
|"All 32-bit single bituint/LSB De Bruijn"|20.32 ns|20.32 ns|34508823|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|969.11 ms|969.07 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1215.33 ms|1215.25 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1543.56 ms|1543.51 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3274.55 ms|3274.41 ms|1|
