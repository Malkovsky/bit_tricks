# Bit tricks



Algorithms for bit manipulation using machine word operations, most of algorithms are adapted from [this](http://www-graphics.stanford.edu/~seander/bithacks.html) page. All benchmarks are for 32-bit words.



# Benchmarks
## Count bits set
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Count bits set naive"|45481.50 ms|45480.80 ms|1|
|"All 32-bit uint/Count bits set iterate set bits"|47470.00 ms|47468.70 ms|1|
|"All 32-bit uint/Count bits set in parallel"|6509.48 ms|6509.22 ms|1|
|"All 32-bit uint/Count bits set with lookup table"|4027.48 ms|4027.29 ms|1|
## Reverse
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/Reverse naive"|69706.30 ms|69703.80 ms|1|
|"All 32-bit uint/Reverse parallel"|6007.00 ms|6006.75 ms|1|
|"All 32-bit uint/Reverse lookup"|4012.22 ms|4012.03 ms|1|
## Select
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Select naive"|8236.11 ms|8235.83 ms|1|
|"All 24-bit uint/Select parallel"|972.11 ms|972.08 ms|1|
## LSB
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 32-bit uint/LSB naive"|3333.20 ms|3333.09 ms|1|
|"All 32-bit uint/LSB parallel"|7737.53 ms|7737.26 ms|1|
|"All 32-bit uint/LSB float"|2763.43 ms|2763.33 ms|1|
|"All 32-bit uint/LSB lookup"|2763.42 ms|2763.31 ms|1|
|"All 32-bit uint/LSB mod lookup"|5034.17 ms|5033.92 ms|1|
|"All 32-bit uint/LSB De Bruijn"|1336.50 ms|1336.47 ms|1|
|"All 32-bit single bit uint/LSB naive"|178.48 ns|178.47 ns|3920321|
|"All 32-bit single bituint/LSB parallel"|45.43 ns|45.43 ns|15379291|
|"All 32-bit single bituint/LSB float"|31.49 ns|31.49 ns|22200071|
|"All 32-bit single bit uint/LSB lookup"|29.65 ns|29.65 ns|23603907|
|"All 32-bit single bituint/LSB mod lookup"|40.95 ns|40.95 ns|17023676|
|"All 32-bit single bituint/LSB De Bruijn"|20.28 ns|20.28 ns|34525183|
## Division
|Benchmark|Time|CPU Time|Iters|
|:--------|---:|-------:|----:|
|"All 24-bit uint/Division by 2^k-1 naive"|969.08 ms|969.06 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v1"|1216.01 ms|1215.96 ms|1|
|"All 24-bit uint/Division by 2^k-1 cycle v2"|1541.73 ms|1541.70 ms|1|
|"All 24-bit uint/Division by 2^k-1 lookup"|3272.52 ms|3272.42 ms|1|
