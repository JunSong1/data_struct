#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#define ERROR 1
#define OK 0

#define MAXSIZE 10

typedef int ElemType;
typedef int Status;

//双链表的数据结构定义
typedef struct DulNode{
    ElemType data;
    struct DulNode *pre;
    struct DulNode *next;
}DulNode;
//双链表结点指针的定义
typedef struct DulNode* DulLinkList;
//双链表的创建
void CreateDulList(DulLinkList *L, int n);
//双链表的遍历
void DisPlayList(DulLinkList L);
//双链表插入结点,在指定位置插入结点
Status InsertNode(DulLinkList *L, int n, ElemType data);
//双链表删除节点,删除指定位置的节点,并返回删除节点的data
Status DeleteNode(DulLinkList *L, int n, ElemType *data);
//双链表中查找某一元素是否存在
Status FindNode(DulLinkList L, ElemType data);
//返回链表长度
int GetListLength(DulLinkList L);
#endif