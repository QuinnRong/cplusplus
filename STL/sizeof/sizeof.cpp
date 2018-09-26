#include <cstdio>
#include <cstring>

/*
单层结构体：
（1）结构体变量中成员的偏移量必须是成员大小的整数倍（0被认为是任何数的整数倍） 
（2）结构体大小必须是所有成员大小的整数倍，也即所有成员大小的公倍数。

嵌套结构体：
（1）展开后的结构体的第一个成员的偏移量应当是被展开的结构体中最大的成员的整数倍。
（2）结构体大小必须是所有成员大小的整数倍，这里所有成员计算的是展开后的成员，而不是将嵌套的结构体当做一个整体。
*/

struct stru1
{
    int i;
    char c;
    int j;
};  // 4 + 1 + (3) + 4 = 12

struct stru2
{
    int i;
    short s;
};  // 4 + 2 + (2) = 8

struct stru3
{
    char a;
    char b;
    int i;
};  // 1 + 1 + (2) + 4 = 8

struct stru4
{
    char a;
    int i;
    char b;
};  // 1 + (3) + 4 + 1 + (3) = 12

struct stru5
{
    long long l;
    double d;
};  // 8 + 8 = 16

int main()
{
    stru1 myStru1;
    printf("sizeof(myStru1) = %d\n", sizeof(myStru1));  // 12

    printf("sizeof(stru1) = %d\n", sizeof(stru1));      // 12
    printf("sizeof(stru2) = %d\n", sizeof(stru2));      // 8
    printf("sizeof(stru3) = %d\n", sizeof(stru3));      // 8
    printf("sizeof(stru4) = %d\n", sizeof(stru4));      // 12
    printf("sizeof(stru5) = %d\n", sizeof(stru5));      // 16

    printf("sizeof(long) = %d\n", sizeof(long));            // 4
    printf("sizeof(long long) = %d\n", sizeof(long long));  // 8

    char str[20] = "hello\0\t";
    printf("sizeof(str) = %d\n", sizeof(str));          // 20
    printf("strlen(str) = %d\n", strlen(str));          // 5
}