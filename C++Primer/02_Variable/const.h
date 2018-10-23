#ifndef CONST_H
#define CONST_H

// declare extern variables, which are defined in const.cpp
extern double pi;
extern const int bufSize;

// const variables are local to file, so different source files can include this
const int zero = 0;
// if non-const variables are included in different source files, they are defined multi times, which should be avoided
// int one = 1;

#endif