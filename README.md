# Bit tricks

Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.

# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|35040.9 ms|34859.4 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|20850.6 ms|20796.9 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6549.02 ms|6546.88 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4862.29 ms|4812.5 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|41555.5 ms|41375 ms|1|
|"All 32-bit uint/Reverse parallel"|6591.53 ms|6578.12 ms|1|
|"All 32-bit uint/Reverse lookup"|5734.34 ms|5703.12 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|5578.93 ms|5531.25 ms|1|
|"All 24-bit uint/Select parallel"|972.037 ms|968.75 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|7035.19 ms|7015.62 ms|1|
|"All 32-bit uint/LSB parallel"|7070.71 ms|7046.88 ms|1|
|"All 32-bit uint/LSB float"|4662.03 ms|4656.25 ms|1|
|"All 32-bit uint/LSB lookup"|5592.16 ms|5546.88 ms|1|
|"All 32-bit uint/LSB mod lookup"|4792.3 ms|4796.88 ms|1|
|"All 32-bit uint/LSB De Bruijn"|5432.46 ms|5406.25 ms|1|
|"All 32-bit single bit uint/LSB naive"|373.221 ns|376.674 ns|1866667|
|"All 32-bit single bituint/LSB parallel"|73.0037 ns|71.4983 ns|8960000|
|"All 32-bit single bituint/LSB float"|51.4849 ns|51.5625 ns|10000000|
|"All 32-bit single bit uint/LSB lookup"|73.0239 ns|72.5446 ns|11200000|
|"All 32-bit single bituint/LSB mod lookup"|61.1797 ns|61.3839 ns|11200000|
|"All 32-bit single bituint/LSB De Bruijn"|57.6431 ns|57.1987 ns|11200000|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|915.748 ms|906.25 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1439.36 ms|1437.5 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1915.16 ms|1906.25 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3165.25 ms|3171.88 ms|1|
