// 本题要求实现对于给定的二叉树，打印后序序列中指定序号的结点。

// 函数接口定义：

// void PrintNode(BiTree T);
// T是二叉树树根指针，PrintNode函数输出给定二叉树的后序序列中第n个结点，n为结点在后序序列中的序号，从1开始编号。

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
// void PrintNode(BiTree T);
// int n;//要打印的结点的在后序序列中的序号
// int main()
// {
//     BiTree T = Create();
//     scanf("%d", &n);
//     printf("The %d-th node in postorder is: ", n);
//     PrintNode(T);
//     printf("\n");
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 输入第一行给出由字母和'#'组成的字符串，代表二叉树的扩展先序序列，第二行给出要打印的结点在后序序列中的序号n。例如对于如下二叉树，输入数据：
// 二叉树.png

// AB#DF##G##C##
// 2
// 输出样例：
// The 2-th node in postorder is: G

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void PrintNode(BiTree T);
int n;  // 要打印的结点的在后序序列中的序号
int main() {
    BiTree T = Create();
    scanf("%d", &n);
    printf("The %d-th node in postorder is: ", n);
    PrintNode(T);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void PrintNode(BiTree T) {
    if (T == NULL) return;
    if (T->lchild != NULL) PrintNode(T->lchild);
    if (T->rchild != NULL) PrintNode(T->rchild);
    if (--n == 0) {
        putchar(T->data);
        return;
    }
}
