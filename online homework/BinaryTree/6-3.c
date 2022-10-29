// 本题要求实现一个函数，按照中序遍历的顺序输出给定二叉树的叶结点。

// 函数接口定义：

// void InorderPrintLeaves( BiTree T);
// T是二叉树树根指针，InorderPrintLeaves按照中序遍历的顺序输出给定二叉树T的叶结点，格式为一个空格跟着一个字符。

// 其中BiTree结构定义如下：

// typedef struct BiTNode
// {
//     ElemType data;
//     struct BiTNode *lchild,*rchild;
// }BiTNode,*BiTree;
// 裁判测试程序样例：

// #include <stdio.h>
// #include <stdlib.h>

// typedef char ElemType;
// typedef struct BiTNode
// {
//     ElemType data;
//     struct BiTNode *lchild,*rchild;
// }BiTNode,*BiTree;

// BiTree Create();/* 细节在此不表 */
// void InorderPrintLeaves( BiTree T);

// int main()
// {
//     BiTree T = Create();
//     printf("Leaf nodes are:");
//     InorderPrintLeaves(T);
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 输入为由字母和'#'组成的字符串，代表二叉树的扩展先序序列。例如对于如下二叉树，输入数据：

// AB#DF##G##C##
// 输出样例（对于图中给出的树）：
// 二叉树.png

// Leaf nodes are: F G C

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void InorderPrintLeaves(BiTree T);

int main() {
    BiTree T = Create();
    printf("Leaf nodes are:");
    InorderPrintLeaves(T);
    return 0;
}
/* 你的代码将被嵌在这里 */

void InorderPrintLeaves(BiTree T){
    if (T == NULL) return;
    if (T->lchild == NULL && T->rchild == NULL) {
        printf(" %c", T->data);
        return;
    }
    if (T->lchild != NULL) InorderPrintLeaves(T->lchild);
    if (T->rchild != NULL) InorderPrintLeaves(T->rchild);
}