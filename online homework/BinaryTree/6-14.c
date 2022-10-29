// 我们知道，完全二叉树的层序编号能够揭示父结点，子结点间的相互关系，因此，完全二叉树能够简单地用数组来表示（有的称为顺序树）。
// 而对于非完全二叉树，用顺序数组表示，就会出现一些不存在的结点处被标示为未用的情况，
// 比如，三个结点的右斜树的数组表示为：{1,-1,3,-1,-1,-1 7}。这里的-1表示是一个空结点。
// 编写函数，根据给定的整数数组（约定正常值为正整数，为-1表示空结点）构造对应的二叉树。
// 二叉树结点类型定义：
// typedef struct BiNode{
//     int data;
//     struct BiNode *lchild,*rchild;
// };
// 输入样例：
// 第一行一个整数，表示数组的长度（数组中的正整数个数是正常的结点个数，-1表示空结点，只是一个占位数）。第二行是数组中存储的顺序树，整数间以空格分隔.。

// 5
// 1 2 -1 4 5
// 输出样例：
// 你只需要构造相应的二叉树并返回根地址，测试程序输出对应的二叉树的前序遍历
// 由于数组{1,2,-1,4,5}对应的二叉树为：

//          1   
//         /
//        2
//      /  \  
//     4    5  
// [1][2][4][5]
// 函数接口定义：
// struct BiNode * fun(int Arr[],int N);
// N 为数组的长度，值为非负整数，函数返回构造的二叉树的根地址（输出由测试程序完成）。

#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode{
    int data;
    struct BiNode *lchild,*rchild;
};

/* 请在这里填写答案 */
struct BiNode *Get(int Arr[], int N, int pos) {
    if (pos >= N || Arr[pos] == -1) return NULL;
    struct BiNode *root = (struct BiNode *)malloc(sizeof(struct BiNode));
    root->data = Arr[pos];
    root->lchild = Get(Arr, N, pos << 1 | 1);
    root->rchild = Get(Arr, N, (pos + 1) << 1);
    return root;
}
struct BiNode *fun(int Arr[], int N) {
    if (N <= 0) return NULL;
    return Get(Arr, N, 0);
}
