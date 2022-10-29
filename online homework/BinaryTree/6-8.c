// 本题要求实现一个函数，统计二叉树的指定层次的结点个数。

// 函数接口定义：

// int  NodeCount(BiTree T,int i);
// T是二叉树树根指针，i为指定层次，树根为第1层，NodeCount返回二叉树中第i层的结点个数，没有返回0。

// 其中BinTree结构定义如下：

// typedef char ElementType;
// typedef struct BiTNode {
//     ElementType data;
//     struct BiTNode *lchild;
//     struct BiTNode *rchild;
// }BiTNode, *BiTree;
// 裁判测试程序样例：

// #include <stdio.h>
// #include <stdlib.h>

// typedef char ElementType;
// typedef struct BiTNode {
//     ElementType data;
//     struct BiTNode *lchild;
//     struct BiTNode *rchild;
// }BiTNode, *BiTree;

// BiTree Create();/* 细节在此不表 */

// int  NodeCount(BiTree T,int i);

// int main()
// {
//    int n;
//     BiTree T = Create();
//     scanf("%d", &n);
//     printf("The num of  nodes in %d-th level is %d.\n",n,NodeCount(T,n));
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 对于图中给出的二叉树，输入数据为两行，第一行是扩展的先序序列，第二行是要输出的层次数：

// 41545570-23e0-4971-b240-dcd21f8986dd.png

// AB#DF##G##C##
// 2
// 输出样例：
// The num of  nodes in 2-th level is 2.

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode {
    ElementType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int NodeCount(BiTree T, int i);

int main() {
    int n;
    BiTree T = Create();
    scanf("%d", &n);
    printf("The num of  nodes in %d-th level is %d.\n", n, NodeCount(T, n));
    return 0;
}
/* 你的代码将被嵌在这里 */
int NodeCount(BiTree T, int i){
    if (T == NULL || i < 1) return 0;
    return NodeCount(T->lchild, i - 1) + NodeCount(T->rchild, i - 1) + (i == 1);
}