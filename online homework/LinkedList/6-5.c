//单链表分段逆转
/*
输入样例：
6
1 2 3 4 5 6
4
输出样例：
4 3 2 1 5 6
*/
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

/*
19分未满
未通过测试点:
1号测试点（正好全反转）
5号测试点（大规模数据，最后剩K-1不反转）
*/

// 题意理解错了，需要将所有K段反转，不是第一个K段
/*
void K_Reverse(List L, int K) {
    if (K <= 1 || L == NULL || L->Next == NULL) return;
    // int n = 1;
    // List o = L->Next;
    // while (o->Next != NULL) ++n, o = o->Next;
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
*/

void K_Reverse(List L, int K) {
    if (K <= 1 || L == NULL || L->Next == NULL) return;
    int n = 1;
    List o = L->Next;
    while (o->Next != NULL) ++n, o = o->Next;
    List head = L;
    List temp, start, pre, cur;
    for (int i = 0; i < n / K; ++i) {
        start = head->Next;
        pre = head->Next;
        cur = pre->Next;
        int j = 1;
        while (j < K) {
            temp = cur->Next;
            cur->Next = pre;
            pre = cur;
            cur = temp;
            ++j;
        }
        start->Next = cur;
        head->Next = pre;
        head = start;
    }
}