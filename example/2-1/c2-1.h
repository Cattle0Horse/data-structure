// c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ
#ifndef C2_1_H
#define C2_1_H

#define LIST_INIT_SIZE 10  // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2    // ���Ա�洢�ռ�ķ�������
struct SqList {
    ElemType *elem;  // �洢�ռ��ַ
    int length;      // ��ǰ����
    int listsize;    // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
};

#endif