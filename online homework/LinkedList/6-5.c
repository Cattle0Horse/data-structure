//单链表分段逆转
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput();       /* 裁判实现，细节不表 */
void PrintList(List L); /* 裁判实现，细节不表 */
void K_Reverse(List L, int K);

int main() {
    freopen("in.txt", "r", stdin);
    List L;
    int K;

    L = ReadInput();
    scanf("%d", &K);
    K_Reverse(L, K);
    PrintList(L);

    return 0;
}

List ReadInput() {
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

void PrintList(List L) {
    List temp = L->Next;
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("%d\n", temp->Data);
}

/* 你的代码将被嵌在这里 */
// 19分未满

void K_Reverse(List L, int K) {
    if (K <= 1 || L == NULL) return;
    int n = 1;
    List temp = L->Next;
    List head = L;
    L = L->Next;
    List pre = NULL;
    int i = 1;
    while (i < K && L != NULL) {
        temp = L->Next;
        L->Next = pre;
        pre = L;
        L = temp;
        ++i;
    }
    if (L == NULL) {
        head->Next->Next = NULL;
        head->Next = pre;
        L = head;
        return;
    }
    head->Next->Next = L->Next;
    L->Next = pre;
    head->Next = L;
    L = head;
}