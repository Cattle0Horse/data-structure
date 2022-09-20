// bo2-1.cpp ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)�Ļ�������(12��)
#ifndef BO2_1_CPP
#define BO2_1_CPP

#include "c1.h"
#include "c2-1.h"

Status InitList(SqList &L)  // �㷨2.3
{                           // �������������һ���յ�˳�����Ա�
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);  // �洢����ʧ��
    L.length = 0;                 // �ձ�����Ϊ0
    L.listsize = LIST_INIT_SIZE;  // ��ʼ�洢����
    return OK;
}

Status DestroyList(SqList &L) {  // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

Status ClearList(SqList &L) {  // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
    L.length = 0;
    return OK;
}

Status ListEmpty(SqList L) {  // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ����򷵻�TRUE�����򷵻�FALSE
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L) {  // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
    return L.length;
}

Status GetElem(SqList L, int i, ElemType &e) {  // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
    // �����������e����L�е�i������Ԫ�ص�ֵ
    if (i < 1 || i > L.length) exit(ERROR);
    e = *(L.elem + i - 1);
    return OK;
}

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {  // ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0)
    // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
    //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6
    ElemType *p;
    int i = 1;   // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L.elem;  // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
    while (i <= L.length && !compare(*p++, e)) ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {  // ��ʼ������˳�����Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
    //           �������ʧ�ܣ�pre_e�޶���
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e) {
        p++;
        i++;
    }
    if (i > L.length)
        return INFEASIBLE;
    else {
        pre_e = *--p;
        return OK;
    }
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {  // ��ʼ������˳�����Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
    //           �������ʧ�ܣ�next_e�޶���
    int i = 1;
    ElemType *p = L.elem;
    while (i < L.length && *p != cur_e) {
        i++;
        p++;
    }
    if (i == L.length)
        return INFEASIBLE;
    else {
        next_e = *++p;
        return OK;
    }
}

Status ListInsert(SqList &L, int i, ElemType e)  // �㷨2.4
{                                                // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1
    // �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
    ElemType *newbase, *q, *p;
    if (i < 1 || i > L.length + 1) return ERROR;  // iֵ���Ϸ�
    if (L.length >= L.listsize)                   // ��ǰ�洢�ռ�����,���ӷ���
    {
        if (!(newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType)))) exit(OVERFLOW);  // �洢����ʧ��
        L.elem = newbase;                                                                                               // �»�ַ
        L.listsize += LISTINCREMENT;                                                                                    // ���Ӵ洢����
    }
    q = L.elem + i - 1;                                          // qΪ����λ��
    for (p = L.elem + L.length - 1; p >= q; --p) *(p + 1) = *p;  // ����λ�ü�֮���Ԫ������
    *q = e;                                                      // ����e
    ++L.length;                                                  // ������1
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)  // �㷨2.5
{                                                 // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
    // ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    ElemType *p, *q;
    if (i < 1 || i > L.length) return ERROR;  // iֵ���Ϸ�
    p = L.elem + i - 1;                       // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                                   // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1;                // ��βԪ�ص�λ��
    for (++p; p <= q; ++p) *(p - 1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
    L.length--;                               // ������1
    return OK;
}

Status ListTraverse(SqList L, void (*vi)(ElemType &)) {  // ��ʼ������˳�����Ա�L�Ѵ���
    // ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ��
    //           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.length; i++) vi(*p++);
    cout << endl;
    return OK;
}

#endif