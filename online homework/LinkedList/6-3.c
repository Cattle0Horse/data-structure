//递增的整数序列链表的插入
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main() {
    // freopen("in.txt", "r", stdin);
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Read() {
    List L = NULL;
    int n;
    scanf("%d", &n);
    if (n <= 0) return L;
    List temp = (List)malloc(sizeof(struct Node));  //生成一个头节点
    scanf("%d", &temp->Data);
    temp->Next = NULL;
    L = temp;
    while (--n) {
        List t = (List)malloc(sizeof(struct Node));
        scanf("%d", &t->Data);
        t->Next = NULL;
        temp->Next = t;
        temp = temp->Next;
    }
    return L;
}

void Print(List L) {
    if (L == NULL) return;
    List temp = L;
    while (temp->Next != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("%d", temp->Data);
}

/* 你的代码将被嵌在这里 */

List Insert(List L, ElementType X) {
    List temp = (List)malloc(sizeof(struct Node));
    temp->Data = X;
    temp->Next = NULL;
    List ans=L;
    while (L->Next != NULL && L->Next->Data < X) L = L->Next;
    temp->Next = L->Next;
    L->Next = temp;
    return ans;
}