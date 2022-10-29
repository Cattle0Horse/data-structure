// 本题要求实现按从下往上打印二叉树中指定元素的祖先。

// 函数接口定义：

// int PrintAncestors(BiTree T,char ch);
// T是二叉树树根指针，ch为指定的元素值，如果ch存在，则PrintAncestors函数按从下到上输出二叉树的ch的所有祖先结点序列，格式为一个字符后面跟着一个空格，并返回1，否则返回0。

// 其中BinTree结构定义如下：

// typedef char ElemType;
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
//     int level;
// }BiTNode, *BiTree;
// BiTree Create();/*细节在此不表*/
// int PrintAncestors(BiTree T,char ch);
// int main()
// {
//     BiTree T = Create();
//     char ch;
//     scanf("\n%c", &ch);
//     int res = PrintAncestors(T,ch);
//     if(!res) printf("%c not exist in this tree!",ch);
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 例如对于如下二叉树，输入数据为2行，第一行为由字母和'#'组成的字符串，代表二叉树的扩展先序序列。第二行为指定元素值：

// AB#DF##G##C##
// F
// 输出样例：
// 对于图中给出的二叉树，输出为：二叉树.png

// D B A

#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct BiTNode {
    ElementType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    int level;
} BiTNode, *BiTree;
BiTree Create(); /*细节在此不表*/
int PrintAncestors(BiTree T, char ch);
int main() {
    BiTree T = Create();
    char ch;
    scanf("\n%c", &ch);
    int res = PrintAncestors(T, ch);
    if (!res) printf("%c not exist in this tree!", ch);
    return 0;
}
/* 你的代码将被嵌在这里 */
int PrintAncestors(BiTree T, char ch){
    if (T == NULL) return 0;
    if (T->data == ch) return 1;
    int left = PrintAncestors(T->lchild, ch), right = PrintAncestors(T->rchild, ch);
    if (left == 1 || right == 1) printf("%c ", T->data);
    return left || right;
}