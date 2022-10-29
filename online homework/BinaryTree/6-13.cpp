// 求根结点到x结点的路径（假定结点值不重复）。

// 函数接口定义：
// bool Findxpath(BiTree bt,char x,vector<char> tmppath,vector<char> &path)    ;
// 裁判测试程序样例：
// #include<iostream>
// #include<stdlib.h>
// #include<vector>

// using namespace std;
// typedef struct BiNode{
//     char data;
//     struct BiNode *lchild,*rchild;
// }BiTNode,*BiTree;

// void CreateBiTree(BiTree &T){
//     char ch;
//     cin>>ch;
//     if(ch=='#')  T=NULL;
//     else{
//         T=new BiTNode;
//         T->data=ch;
//         CreateBiTree(T->lchild);
//         CreateBiTree(T->rchild);
//     }
// }

// bool Findxpath(BiTree bt,char x,vector<char> tmppath,vector<char> &path);

// int main(){
//     BiTree T;
//     char x;
//     vector<char>tmppath;
//     vector<char>path;    
//     CreateBiTree(T);
//     cin>>x;
//     Findxpath(T,x,tmppath,path);
//     for(int i=0;i<path.size();i++)
//         cout<<path[i]<<" ";
//     return 0;
// }

// /* 请在这里填写答案 */
// 输入样例：
// 输入一行字符序列先序递归构建二叉树。每个字符对应一个结点，#表示空结点。第二行输入一个结点值x。

// 52#3##41##6##
// 3
// 输出样例：
// 输出从根到结点x的路径。

// 5 2 3

#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;
typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path);

int main() {
    BiTree T;
    char x;
    vector<char> tmppath;
    vector<char> path;
    CreateBiTree(T);
    cin >> x;
    Findxpath(T, x, tmppath, path);
    for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
    return 0;
}

/* 请在这里填写答案 */
bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path) {
    if (bt == NULL) return false;
    tmppath.push_back(bt->data);//放入当前节点
    if (bt->data == x) {//如果找到x返回true
        path = tmppath;
        return true;
    }
    if (Findxpath(bt->lchild, x, tmppath, path)) return true;//如果所求在左子树
    return Findxpath(bt->rchild, x, tmppath, path);//否则在右子树
}