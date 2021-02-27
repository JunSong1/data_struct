#include <stdio.h>
#include <stdlib.h>
#include "../inc/double_list.h"

//˫����Ĵ���
void CreateDulList(DulLinkList *L, int n)
{
    DulLinkList me, ptr;
    int i;
    (*L) = (DulLinkList)malloc(sizeof(DulNode));    //Ϊͷ�������ռ�
    (*L)->next = NULL;
    (*L)->pre = NULL;
    (*L)->data = n;
    ptr = (*L);
    for(i = 0; i < n; i++)
    {
        me = (DulLinkList)malloc(sizeof(DulNode));
        me->data = rand()%100 + 1;    //�ڵ�������
        me->next = NULL;
        me->pre = NULL;

        ptr->next = me;
        me->pre = ptr;
        ptr = ptr->next;
    }

}
//˫����ı���
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
//����������
int GetListLength(DulLinkList L)
{
    return L->data;
}
//˫���������,��ָ��λ�ò�����
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
        
    else if(n == 1)      //�����ͷ
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
//˫����ɾ���ڵ�,ɾ��ָ��λ�õĽڵ�,������ɾ���ڵ��data
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
//˫�����в���ĳһԪ���Ƿ����
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