//求链式表的表长
/*
输入样例：
1 3 4 5 2 -1
输出样例：
5
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length(List L);

int main() {
    List L = Read();
    printf("%d\n", Length(L));
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

int Length(List L) {
    if (L == NULL) return 0;
    int n = 1;
    List now = L;
    while (now->Next != NULL) ++n, now = now->Next;
    return n;
}