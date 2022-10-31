// c3-2.h 单链队列－－队列的链式存储结构
#ifndef C3_2_H
#define C3_2_H

typedef struct QNode {
    QElemType data;
    QNode *next;
} * QueuePtr;

struct LinkQueue {
    QueuePtr front, rear;  // 队头、队尾指针
};

#endif