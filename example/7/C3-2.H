// c3-2.h �������У������е���ʽ�洢�ṹ
typedef struct QNode {
    QElemType data;
    QNode *next;
} * QueuePtr;

struct LinkQueue {
    QueuePtr front, rear;  // ��ͷ����βָ��
};