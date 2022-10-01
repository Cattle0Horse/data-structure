//单链表逆转
/*
输入样例：
5
1 3 4 5 2
输出样例：
1
2 5 4 3 1
*/
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

List Reverse(List L);

int main() {
    // freopen("in.txt","r",stdin);
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
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
    printf("%d\n", temp->Data);
}

/* 你的代码将被嵌在这里 */

List Reverse(List L) {
    List t, ans;
    ans = NULL;
    while (L != NULL) {
        t = L->Next;
        L->Next = ans;
        ans = L;
        L = t;
    }
    return ans;
}