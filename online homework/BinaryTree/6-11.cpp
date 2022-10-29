// 后序+中序序列构造二叉树（递归法）

// 函数接口定义：
// struct node * xx(char *post,char *in,int len);
// post 为后序序列； in 为中序序列； len 为序列长度。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <iostream>
// #include <stdlib.h>
// #define N 1000
// using namespace std;
// struct node{
//   char data;
//   struct node * lchild;
//   struct node * rchild;
// };

// struct node * xx(char *post,char *in,int len);

// void Preorder(struct node * root)
// {
//   if(root)
//   {
//     cout<<root->data;
//     Preorder(root->lchild);
//     Preorder(root->rchild);
//   }
// }

// int main()
// {
//   int n,i;
//   char post[N];
//   char in[N];
//   cin>>n;
//   for(i=0;i<n;i++)
//     cin>>post[i];
//   for(i=0;i<n;i++)
//     cin>>in[i];
//   struct node *root=xx(post,in,n);
//   Preorder(root);
//   return 0;
// }

// /* 请在这里填写答案 */
// 输入样例：
// 第一行输入序列长度n，第二行输入n个字符表示二叉树后序遍历的序列，第三行输入n个字符表示二叉树中序遍历的序列

// 9
// GHDBEIFCA
// GDHBAECIF
// 输出样例：
// 输出二叉树先序遍历的序列。

// ABDGHCEFI

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#define N 1000
using namespace std;
struct node {
    char data;
    struct node *lchild;
    struct node *rchild;
};
struct node *xx(char *post, char *in, int len);
void Preorder(struct node *root) {
    if (root) {
        cout << root->data;
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}
int main() {
    int n, i;
    char post[N];
    char in[N];
    cin >> n;
    for (i = 0; i < n; i++) cin >> post[i];
    for (i = 0; i < n; i++) cin >> in[i];
    struct node *root = xx(post, in, n);
    Preorder(root);
    return 0;
}

/* 请在这里填写答案 */
struct node *xx(char *post, char *in, int len) {
    if (len <= 0) return NULL;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = post[len - 1];
    int pos = 0;
    while (pos < len) {
        if (in[pos] == root->data) break;
        ++pos;
    }
    root->lchild = xx(post, in, pos);
    root->rchild = xx(post + pos, in + pos + 1, len - pos - 1);
    return root;
}