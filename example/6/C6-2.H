// c6-2.h 二叉树的二叉链表存储表示
#ifndef C6_2_H
#define C6_2_H

typedef struct BiTNode {
    TElemType data;
    BiTNode *lchild, *rchild;  // 左右孩子指针
} BiTNode, *BiTree;

#endif