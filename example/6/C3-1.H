// c3-1.h ջ��˳��洢��ʾ
#define STACK_INIT_SIZE 10  // �洢�ռ��ʼ������
#define STACKINCREMENT 2    // �洢�ռ��������
struct SqStack {
    SElemType *base;  // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top;   // ջ��ָ��
    int stacksize;    // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
};                    // ˳��ջ