// 本题要求用非递归的方法实现对给定二叉树的 3 种遍历。

// 函数接口定义：
// void InorderTraversal( BinTree BT );
// void PreorderTraversal( BinTree BT );
// void PostorderTraversal( BinTree BT );
// 其中BinTree结构定义如下：

// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
//     int flag;
// };
// 要求 3 个函数分别按照访问顺序打印出结点的内容，格式为一个空格跟着一个字符。

// 此外，裁判程序中给出了堆栈的全套操作，可以直接调用。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>
// typedef enum { false, true } bool;

// typedef char ElementType;
// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
//     int flag;
// };

// /*------堆栈的定义-------*/
// typedef Position SElementType;
// typedef struct SNode *PtrToSNode;
// struct SNode {
//     SElementType Data;
//     PtrToSNode Next;
// };
// typedef PtrToSNode Stack;

// /* 裁判实现，细节不表 */
// Stack CreateStack();
// bool IsEmpty( Stack S );
// bool Push( Stack S, SElementType X );
// SElementType Pop( Stack S ); /* 删除并仅返回S的栈顶元素 */
// SElementType Peek( Stack S );/* 仅返回S的栈顶元素 */
// /*----堆栈的定义结束-----*/

// BinTree CreateBinTree(); /* 裁判实现，细节不表 */
// void InorderTraversal( BinTree BT );
// void PreorderTraversal( BinTree BT );
// void PostorderTraversal( BinTree BT );

// int main()
// {
//     BinTree BT = CreateBinTree();
//     printf("Inorder:");    InorderTraversal(BT);    printf("\n");
//     printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
//     printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输入样例：
// 如图
// tree.jpg

// 输出样例：
// Inorder: D B E F A G H C I
// Preorder: A B D F E C G H I
// Postorder: D E F B H G I C A
#include <stdio.h>
#include <stdlib.h>
typedef enum { false,
               true } bool;

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S);  /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S); /* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main() {
    BinTree BT = CreateBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    BinTree t = BT;
    Stack s = CreateStack();
    while (t != NULL || !IsEmpty(s)) {
        while (t != NULL) {  // 左子树入栈
            Push(s, t);
            t = t->Left;
        }
        t = Pop(s);
        printf(" %c", t->Data);  // 输出堆顶，即最左儿子
        t = t->Right;            // 访问右子树
    }

    // if(BT==NULL)return;
    // InorderTraversal(BT->Left);
    // printf(" %c", BT->Data);
    // InorderTraversal(BT->Right);
}
void PreorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    BinTree now = BT;
    Stack s = CreateStack();
    Push(s, now);
    while (!IsEmpty(s)) {
        now = Pop(s);  // 取出堆顶，即当前树的根
        printf(" %c", now->Data);
        if (now->Right != NULL) Push(s, now->Right);  // 先入右节点，因为右节点后输出
        if (now->Left != NULL) Push(s, now->Left);
    }

    // if (BT == NULL) return;
    // BinTree t = BT;
    // Stack s = CreateStack();
    // while (t != NULL || !IsEmpty(s)) {
    //     while (t != NULL) {
    //         Push(s, t);
    //         printf(" %c", t->Data);
    //         t = t->Left;
    //     }
    //     t = Pop(s);
    //     t = t->Right;
    // }

    // if (BT == NULL) return;
    // printf(" %c", BT->Data);
    // PreorderTraversal(BT->Left);
    // PreorderTraversal(BT->Right);
}
void PostorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    BinTree t = BT;
    Stack s = CreateStack();
    while (t != NULL || !IsEmpty(s)) {
        while (t != NULL) {  // 左下角遍历挨个入栈
            t->flag = 0;
            Push(s, t);
            t = t->Left;
        }
        // 此时为最左下角的
        t = Peek(s);
        if (t->flag == 0) {  // 首次入栈
            t->flag = 1;
            t = t->Right;
        } else {  // 非首次入栈，输出栈顶
            t = Pop(s);
            printf(" %c", t->Data);
            t = NULL;
        }
    }

    // if (BT == NULL) return;
    // PostorderTraversal(BT->Left);
    // PostorderTraversal(BT->Right);
    // printf(" %c", BT->Data);
}