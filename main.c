#include <stdio.h>
#include <stdlib.h>
#include "../inc/double_list.h"

int main()
{
    DulLinkList me;
    int num = 10, data = 44;
    CreateDulList(&me, num);
    DisPlayList(me);
    printf("double list length = %d\n", me->data);
    InsertNode(&me, 12, data);
    DisPlayList(me);
    printf("double list length = %d\n", me->data);
    DeleteNode(&me, 6, &data);
    printf("delete Node data=%d\n", data);
    DisPlayList(me);
    printf("double list length = %d\n", me->data);
    printf("find node result=%d\n", FindNode(me, 45));
    return 0;
}