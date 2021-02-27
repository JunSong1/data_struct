#include <stdio.h>
#include <stdlib.h>
#include "../inc/double_list.h"

//双链表的创建
void CreateDulList(DulLinkList *L, int n)
{
    DulLinkList me, ptr;
    int i;
    (*L) = (DulLinkList)malloc(sizeof(DulNode));    //为头结点申请空间
    (*L)->next = NULL;
    (*L)->pre = NULL;
    (*L)->data = n;
    ptr = (*L);
    for(i = 0; i < n; i++)
    {
        me = (DulLinkList)malloc(sizeof(DulNode));
        me->data = rand()%100 + 1;    //节点数据域
        me->next = NULL;
        me->pre = NULL;

        ptr->next = me;
        me->pre = ptr;
        ptr = ptr->next;
    }

}
//双链表的遍历
void DisPlayList(DulLinkList L)
{
    DulLinkList me;
    me = L->next;
    for(;me != NULL; me = me->next)
    {
        printf("%d ",me->data);
    }
    printf("\n");
}
//返回链表长度
int GetListLength(DulLinkList L)
{
    return L->data;
}
//双链表插入结点,在指定位置插入结点
Status InsertNode(DulLinkList *L, int n, ElemType data)
{
    DulLinkList me,ptr,prev;
    me = (DulLinkList)malloc(sizeof(DulNode));
    me->data = data;
    me->pre = NULL;
    me->next = NULL;

    ptr = (*L)->next;
    if(n < 1 || n > (*L)->data)
    {
        printf("insert location is error! please check your insert location.\n");
        return ERROR;
    }
        
    else if(n == 1)      //插入表头
    {
        me->next = ptr;
        ptr->pre = me;
        (*L)->next = me;
        me->pre = (*L);
        ((*L)->data)++;
        return OK;
    }
    else{
        for(int i = 0; i < n; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        me->next = ptr;
        ptr->pre = me;
        prev->next = me;
        me->pre = prev;

        ((*L)->data)++;
        return OK;
    }
}
//双链表删除节点,删除指定位置的节点,并返回删除节点的data
Status DeleteNode(DulLinkList *L, int n, ElemType *data)
{
    DulLinkList me,ptr;
    me = (*L);
    if(n < 1 || n > (me->data))
    {
        printf("delete location is error! please check your delete location.\n");
        return ERROR;
    }
    else if(n == 1)
    {
        ptr = me->next;
        me->next = ptr->next;
        ptr->next->pre = me;
        *data = ptr->data;
        free(ptr);
        ((*L)->data)--;
        return OK;
    }
    else{
        me = me->next;
        for(int i = 1; i < n; i++)
        {
            ptr = me;
            me = me->next;
        }

        ptr->next = me->next;
        me->next->pre = ptr;
        (*data) = me->data;
        free(me);
        ((*L)->data)--;
        return OK;
    }
}
//双链表中查找某一元素是否存在
Status FindNode(DulLinkList L, ElemType data)
{
    DulLinkList me;
    int Location = 1;
    me = L->next;
    for(; me != NULL; me = me->next, Location++)
    {
        if(data == me->data)
            break;
        else
            continue;
    }
    if(Location < L->data)
        return Location;
    else
        return ERROR;
}