// c1.h (������)

#ifndef C1_H
#define C1_H

using namespace std;
#include <ctype.h>
#include <io.h>       // eof()
#include <limits.h>   // INT_MAX��
#include <malloc.h>   // malloc()��
#include <math.h>     // floor(),ceil(),abs()
#include <process.h>  // exit()
#include <stdio.h>    // EOF(=^Z��F6),NULL
#include <stdlib.h>   // atoi()
#include <string.h>

#include <iostream>  // cout,cin
// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
typedef int Status;   // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean;  // Boolean�ǲ�������,��ֵ��TRUE��FALSE

#endif
