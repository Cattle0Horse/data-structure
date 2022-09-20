// c1.h (程序名)

#ifndef C1_H
#define C1_H

using namespace std;
#include <ctype.h>
#include <io.h>       // eof()
#include <limits.h>   // INT_MAX等
#include <malloc.h>   // malloc()等
#include <math.h>     // floor(),ceil(),abs()
#include <process.h>  // exit()
#include <stdio.h>    // EOF(=^Z或F6),NULL
#include <stdlib.h>   // atoi()
#include <string.h>

#include <iostream>  // cout,cin
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
typedef int Status;   // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean;  // Boolean是布尔类型,其值是TRUE或FALSE

#endif
