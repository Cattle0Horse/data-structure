// 先序序列+中序序列建立二叉树（递归法）

// 函数接口定义：
// BiTree CreateBTree(char a[],char b[],int n);
// a 为先序序列； b 是中序序列； n 是序列长度。

// 裁判测试程序样例：
// #include<iostream>
// #define N 100
// using namespace std;

// typedef struct BiNode
// {                
//     char data;                        
//     struct BiNode *lchild,*rchild;
// }BiTNode,*BiTree;
    
// void LRD(BiTree T)
// {  
//     if(T){
//         LRD(T->lchild);
//         LRD(T->rchild);
//         cout << T->data;        
//     }
// }    

// BiTree CreateBTree(char a[],char b[],int n);

// int main()
// {   BiTree T;
//     int n,i;
//     char a[N],b[N];
//     cin>>n;
//     for(i=0;i<n;i++)
//       cin>>a[i];
//     for(i=0;i<n;i++)
//       cin>>b[i];      
//     T=CreateBTree(a,b,n);
//     LRD(T);
//     return 0;
// }

// /* 请在这里填写答案 */
// 输入样例：
// 第一行输入序列长度n，第二行输入n个字符表示二叉树先序遍历的序列，第三行输入n个字符表示二叉树中序遍历的序列

// 9
// ABDGHCEFI
// GDHBAECIF
// 输出样例：
// 输出二叉树后序遍历的序列。

// GHDBEIFCA

#include <iostream>
#define N 100
using namespace std;
typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;
void LRD(BiTree T) {
    if (T) {
        LRD(T->lchild);
        LRD(T->rchild);
        cout << T->data;
    }
}
BiTree CreateBTree(char a[], char b[], int n);
int main() {
    BiTree T;
    int n, i;
    char a[N], b[N];
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    T = CreateBTree(a, b, n);
    LRD(T);
    return 0;
}

/* 请在这里填写答案 */
BiTree CreateBTree(char a[], char b[], int n) {
    if (n <= 0) return NULL;//如果当前树节点数为0则赋为空节点
    BiTree T = new BiNode;
    T->data = *a;//根节点
    int pos = 0;//找到中序遍历中的根节点位置
    while (pos < n) {
        if (b[pos] == a[0]) break;
        ++pos;
    }
    T->lchild = CreateBTree(a + 1, b, pos);//找左子树
    T->rchild = CreateBTree(a + pos + 1, b + pos + 1, n - pos - 1);  // 找右子树
    return T;
}