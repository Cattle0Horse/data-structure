// 6-4 在一个数组中实现两个堆栈
/*
输入样例：
5
Push 1 1
Pop 2
Push 2 11
Push 1 2
Push 2 12
Pop 1
Push 2 13
Push 2 14
Push 1 3
Pop 2
End
输出样例：
Stack 2 Empty
Stack 2 is Empty!
Stack Full
Stack 1 is Full!
Pop from Stack 1: 1
Pop from Stack 2: 13 12 11
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push,
               pop,
               end } Operation;
typedef enum { false,
               true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();                 /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main() {
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
        case push:
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

Stack CreateStack(int MaxSize) {
    Stack stack = (Stack)malloc(sizeof(Stack));
    stack->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    return stack;
}
bool Push(Stack S, ElementType X, int Tag) {
    if (!S) return false;
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return true;
}
ElementType Pop(Stack S, int Tag) {
    if (!S) return ERROR;
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    } else {
        if (S->Top2 == S->MaxSize) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];
    }
}