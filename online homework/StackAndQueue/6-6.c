// 6-6 循环队列操作集
/*
输入样例：
4
Del
Add 5
Add 4
Add 3
Del
Del
Add 2
Add 1
Add 0
End
输出样例：
Queue Empty
5 is out
4 is out
Queue Full
3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { addq,
               delq,
               end } Operation;
typedef enum { false,
               true } bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;    /* 存储元素的数组   */
    Position Front, Rear; /* 队列的头、尾指针 */
    int MaxSize;          /* 队列最大容量     */
};
typedef PtrToQNode Queue;

Operation GetOp(); /* 裁判实现，细节不表 */

Queue CreateQueue(int MaxSize);
bool AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);

int main() {
    ElementType X;
    Queue Q;
    int N, done = 0;

    scanf("%d", &N);
    Q = CreateQueue(N);
    while (!done) {
        switch (GetOp()) {
        case addq:
            scanf("%d", &X);
            AddQ(Q, X);
            break;
        case delq:
            X = DeleteQ(Q);
            if (X != ERROR) printf("%d is out\n", X);
            break;
        case end:
            while (Q->Front != Q->Rear) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */


Queue CreateQueue(int MaxSize) {
    Queue ret = (Queue)malloc(sizeof(struct QNode));
    ret->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    ret->Front = ret->Rear = 0;
    ret->MaxSize = MaxSize;
    return ret;
}
bool AddQ(Queue Q, ElementType X) {
    if ((Q->Rear + 1) % Q->MaxSize == Q->Front) {
        printf("Queue Full\n");
        return false;
    }
    Q->Data[Q->Rear++] = X;
    Q->Rear %= Q->MaxSize;
    return true;
}
ElementType DeleteQ(Queue Q) {
    if (Q->Rear == Q->Front) {
        printf("Queue Empty\n");
        return ERROR;
    }
    ElementType ret = Q->Data[Q->Front++];
    Q->Front %= Q->MaxSize;
    return ret;
}