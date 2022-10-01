//链式表的按序号查找
/*
输入样例：
1 3 4 5 2 -1
6
3 6 1 5 4 2
输出样例：
4 NA 1 2 5 3 
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K);

int main() {
    // freopen("in.txt", "r", stdin);
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read() {
    List L = NULL;
    List temp = (List)malloc(sizeof(struct LNode));  //生成一个头节点
    scanf("%d", &temp->Data);
    temp->Next = NULL;
    L = temp;
    int elm;
    while (scanf("%d", &elm), ~elm) {
        List t = (List)malloc(sizeof(struct LNode));
        t->Data = elm;
        t->Next = NULL;
        temp->Next = t;
        temp = temp->Next;
    }
    return L;
}

/* 你的代码将被嵌在这里 */

ElementType FindKth(List L, int K) {
    if (L == NULL) return ERROR;
    int n = 1;
    List t = L;
    while (n < K && t->Next != NULL) t = t->Next, ++n;
    return n == K ? t->Data : ERROR;
}