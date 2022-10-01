//求链表的倒数第m个元素
/*
输入样例：
5
1 2 4 5 6
3
输出样例：
4
1 2 4 5 6 
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main() {
    freopen("in.txt", "r", stdin);
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

List Read() {
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    head->Data = -1;
    int n;
    scanf("%d", &n);
    if (n <= 0) return head;
    List temp = head;
    while (n--) {
        List t = (List)malloc(sizeof(struct Node));
        scanf("%d", &t->Data);
        t->Next = NULL;
        temp->Next = t;
        temp = temp->Next;
    }
    return head;
}

void Print(List L) {
    List temp = L->Next;
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("%d\n", temp->Data);
}

/* 你的代码将被嵌在这里 */

ElementType Find(List L, int m) {
    if (m <= 0 || L == NULL || L->Next == NULL) return ERROR;
    List temp = L->Next;
    int n = 1;
    while (temp->Next != NULL) ++n, temp = temp->Next;
    if (m > n) return ERROR;
    temp = L->Next;
    n = n - m + 1;
    for (int i = 1; i < n; ++i, temp = temp->Next) 114514;
    return temp->Data;
}