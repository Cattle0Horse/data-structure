// 6-1 另类循环队列
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
Add 10
End
输出样例：
Queue Empty
5 is out
4 is out
Queue Full
3 2 1 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    ElementType *Data; /* 存储元素的数组   */
    Position Front;    /* 队列的头、尾指针 */
    int Count;         /* 队列中元素个数   */
    int MaxSize;       /* 队列最大容量     */
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
 
bool AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);

Operation GetOp(); /* 裁判实现，细节不表 */

int main() {
    //freopen("in.txt", "r", stdin);
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
            while (Q->Count) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }
    return 0;
}
Operation GetOp() {
    char a[4];
    scanf("%s", a);
    a[3] = '\0';
    if (!strcmp(a, "Del")) return delq;
    if (!strcmp(a, "Add")) return addq;
    return end;
}
/* 你的代码将被嵌在这里 */

bool AddQ(Queue Q, ElementType X) {
    if (Q->Count >= Q->MaxSize) {
        puts("Queue Full");
        return false;
    }
    Q->Data[(Q->Front + Q->Count) % Q->MaxSize] = X;
    ++Q->Count;
    return true;
}
ElementType DeleteQ(Queue Q) {
    if (!Q->Count) {
        puts("Queue Empty");
        return ERROR;
    }
    int now = Q->Data[Q->Front];
    ++Q->Front, Q->Front %= Q->MaxSize;
    --Q->Count;
    return now;
}