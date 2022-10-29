// 本题要求实现对于给定的二叉树，打印层次遍历序列中指定序号的结点。

// 函数接口定义：

// void PrintNode(BiTree T,int n);
// T是二叉树树根指针，PrintNode函数输出给定二叉树的层次遍历序列中第n个结点，n为结点在层次遍历序列中的序号，从1开始编号。

// 其中BinTree结构定义如下：

// typedef char ElemType;
// typedef struct BiTNode
// {
//    ElemType data;
//    struct BiTNode *lchild, *rchild;
// }BiTNode, *BiTree;
// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>

// typedef char ElemType;
// typedef struct BiTNode
// {
//     ElemType data;
//     struct BiTNode *lchild, *rchild;
// }BiTNode, *BiTree;

// BiTree Create();/* 细节在此不表 */

// void PrintNode(BiTree T,int n);
// int main()
// {
//     BiTree T = Create();
//     int n;
//     scanf("%d", &n);
//     printf("The %d-th node in levelorder is: ", n);
//     PrintNode(T,n);
//     printf("\n");
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 输入第一行给出由字母和'#'组成的字符串，代表二叉树的扩展先序序列，第二行给出要打印的结点在后序序列中的序号n。例如对于如下二叉树，输入数据：
// 二叉树.png

// AB#DF##G##C##
// 2
// 输出样例（对于图中给出的树，当输入的n为2时）：
// The 2-th node in levelorder is: B

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

void PrintNode(BiTree T, int n);
int main() {
    BiTree T = Create();
    int n;
    scanf("%d", &n);
    printf("The %d-th node in levelorder is: ", n);
    PrintNode(T, n);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void PrintNode(BiTree T, int n) {
    if (T == NULL || n < 1) return;
    BiTree queue[n];  // 数组模拟队列
    int left = 0, right = 0;
    queue[right++] = T;
    while (left < right) {
        BiTree now = queue[left++];
        if (--n == 0) {
            putchar(now->data);
            return;
        }
        if (now->lchild != NULL) queue[right++] = now->lchild;
        if (now->rchild != NULL) queue[right++] = now->rchild;
    }
}