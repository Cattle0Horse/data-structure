//两个有序链表序列的合并
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
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
    freopen("in.txt", "r", stdin);
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    scanf("%d", &head->Data);
    if (head->Data <= 0) return head;
    List temp = head;
    for (int i = 0; i < head->Data; ++i) {
        List t = (List)malloc(sizeof(struct Node));
        scanf("%d", &t->Data);
        t->Next = NULL;
        temp->Next = t;
        temp = temp->Next;
    }
    return head;
}

void Print(List L) {
    if (L->Next == NULL) {
        printf("NULL\n");
        return;
    }
    List temp = L;
    while (temp->Next != NULL) {
        temp = temp->Next;
        printf("%d ", temp->Data);
    }
    puts("");
}

/* 你的代码将被嵌在这里 */

//重点注意L1-L2最后要是空链表，要用新指针讲两个链表所对应的元素连起来，再将L1-L2置空
//如果用ans跟着指向L1-L2，当L1,L2置空时，ans也会
List Merge(List L1, List L2) {
    List ans = (List)malloc(sizeof(struct Node));
    List temp = ans;
    List l = L1->Next, r = L2->Next;
    while (l != NULL && r != NULL) {
        if (l->Data <= r->Data) {
            temp->Next = l;
            l = l->Next;
        } else {
            temp->Next = r;
            r = r->Next;
        }
        temp = temp->Next;
    }
    if (r != NULL) temp->Next = r;
    if (l != NULL) temp->Next = l;
    L1->Next = NULL, L2->Next = NULL;
    return ans;
}