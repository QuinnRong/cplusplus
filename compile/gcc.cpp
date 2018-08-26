/*
gcc gcc.c -o gcc 			所有文件重新编译

gcc -E gcc.c -o gcc.i 		预处理
gcc -E -o gcc.o gcc.c
gcc -S gcc.i -o gcc.s 		编译
gcc -S -o gcc.s gcc.i
gcc -c gcc.s -o gcc.o 		汇编
gcc -c -o gcc.o gcc.s
gcc gcc.o -o gcc 			链接,只重新编译修改的文件
gcc -o gcc gcc.o

-Wall 						编译后显示所有警告
-g 							可用于 gdb 调试

-O0			不进行任何优化，在这种情况下，编译器尽量的缩短编译消耗（时间，空间），此时，debug会产出和程序预期的结果。
-O1			优化会消耗少多的编译时间，它主要对代码的分支，常量以及表达式等进行优化。 
-O2			会尝试更多的寄存器级的优化以及指令级的优化，它会在编译期间占用更多的内存和编译时间。 
-O3			在O2的基础上进行更多的优化，例如使用伪寄存器网络，普通函数的内联，以及针对循环的更多优化。 
-Os			主要是对代码大小的优化，我们基本不用做更多的关心。

-I 			查找头文件目录，默认包括当前目录、/usr/include和/usr/local/include
-L 			查找库文件目录，默认包括当前目录、/lib、/usr/lib和/usr/local/lib
-lword		寻找动态链接库文件 libword.so，如果加上编译选项-static，表示寻找静态链接库文件，也就是libword.a。
			对于第三方提供的动态链接库(.so），一般将其拷贝到一个lib目录下(/usr/local/lib），或者使用-L来指定其所在目录， 然后使用-l来指定其名称。
			常见的库链接方法为： 
-lpthread 	是posix线程，
-lc 		是link libc，
-lm 		是link libm，数学库
-lz 		是link libz，

Makefile:
%.o : %.c
	gcc -c -o $@ $^

目标文件：依赖文件
(1) $@ ——目标文件的名称；
(2) $^ ——所有的依赖文件，以空格分开，不包含重复的依赖文件；
(3) $< ——第一个依赖文件的名称。

所有的.o文件，依赖于对应的.c文件。比如有三个a.c b.c c.c，那么就会有 a.o b.o c.o
a.o : a.c
b.o : b.c
c.o : c.c

*/

#include <stdio.h>

int main(){
	printf("%s\n", "Hello world!");
}