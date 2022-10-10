// 6-5 数据结构考题 - 链队列
/*
输入格式:
在一行输入若干个队列元素值，调用入队函数把输入的元素值入队，用−1表示输入结束（−1不属于队列）。

输出格式:
输出分两行：

第一行输出队头元素。如队列为空，输出NULL。

第二行依次输出出队元素，直到队列为空。元素间以空格分隔，队列为空时输出NULL。

输入样例:
1 3 5 7 9 -1
输出样例:
Head:1
Pop:1 3 5 7 9 NULL
输入样例:
-1
输出样例:
Head:NULL
Pop:NULL
*/
 
#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkQueue;

bool GetHead(LinkQueue Q, ElemType &e) {
    if (Q.front == Q.rear) {
        cout << "NULL" << endl;
        return false;
    }
    e = Q.front->next->data;
    return true;
}

void EnQueue(LinkQueue &Q, ElemType e) {
    QNode *p;
    p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = Q.rear->next;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
    QNode *p;
    if (Q.front == Q.rear) {
        cout << "NULL" << endl;
        return false;
    }
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}

void InitQNode(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.front = NULL;
}

int main() {
    LinkQueue Q;
    ElemType x, e;
    InitQNode(Q);
    cin >> x;
    while (x != -1) {
        EnQueue(Q, x);
        cin >> x;
    }
    cout << "Head:";
    if (GetHead(Q, e)) cout << e << endl;
    cout << "Pop:";
    while (DeQueue(Q, e)) cout << e << ' ';
    return 0;
}
