#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#define ERROR 1
#define OK 0

#define MAXSIZE 10

typedef int ElemType;
typedef int Status;

//˫��������ݽṹ����
typedef struct DulNode{
    ElemType data;
    struct DulNode *pre;
    struct DulNode *next;
}DulNode;
//˫������ָ��Ķ���
typedef struct DulNode* DulLinkList;
//˫����Ĵ���
void CreateDulList(DulLinkList *L, int n);
//˫����ı���
void DisPlayList(DulLinkList L);
//˫���������,��ָ��λ�ò�����
Status InsertNode(DulLinkList *L, int n, ElemType data);
//˫����ɾ���ڵ�,ɾ��ָ��λ�õĽڵ�,������ɾ���ڵ��data
Status DeleteNode(DulLinkList *L, int n, ElemType *data);
//˫�����в���ĳһԪ���Ƿ����
Status FindNode(DulLinkList L, ElemType data);
//����������
int GetListLength(DulLinkList L);
#endif