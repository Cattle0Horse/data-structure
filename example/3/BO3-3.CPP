// bo3-3.cpp 循环队列(存储结构由c3-3.h定义)的基本操作(9个)
Status InitQueue(SqQueue &Q) {  // 构造一个空队列Q
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)  // 存储分配失败
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q) {  // 销毁队列Q,Q不再存在
    if (Q.base)
        free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return OK;
}

Status ClearQueue(SqQueue &Q) {  // 将Q清为空队列
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q) {  // 若队列Q为空队列,则返回TRUE,否则返回FALSE
    if (Q.front == Q.rear)      // 队列空的标志
        return TRUE;
    else
        return FALSE;
}

int QueueLength(SqQueue Q) {  // 返回Q的元素个数,即队列的长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue Q, QElemType &e) {  // 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR
    if (Q.front == Q.rear)                 // 队列空
        return ERROR;
    e = *(Q.base + Q.front);
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e) {    // 插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAXQSIZE == Q.front)  // 队列满
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e) {  // 若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;否则返回ERROR
    if (Q.front == Q.rear)                  // 队列空
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status QueueTraverse(SqQueue Q, void (*vi)(QElemType)) {  // 从队头到队尾依次对队列Q中每个元素调用函数vi().一旦vi失败,则操作失败
    int i;
    i = Q.front;
    while (i != Q.rear) {
        vi(*(Q.base + i));
        i = (i + 1) % MAXQSIZE;
    }
    printf("\n");
    return OK;
}