# string-replacement



## Usage

`mkdir buil`

`cmake ..`

`make`

`./test`



## Finished

naïve approach: 迭代地更新指数(exponent)数组 



## TODO

对于形如“...01011”这种序列，先更新为“...01111”，并记录该位置为“0 0 -1 0 0”，然后更新为“...1 0 0 0 -1”，然后把两者结合为“...1 0 -1 0 -1”。

0地前后至少要有3个1，“...1011...”，“...1101...”，否则性能degrade
