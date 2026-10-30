#include "apc.h"

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    if(tail1 == NULL || tail2 == NULL) return LIST_EMPTY;

    Dlist *t1;
    Dlist *t2=tail2;

    Dlist *temp1_h=NULL;
    Dlist *temp1_t=NULL;

    Dlist *temp2_h=NULL;
    Dlist *temp2_t=NULL;

    int carry;
    int prod;
    int count=0;

    while(t2)
    {
        t1=tail1;
        carry=0;

        while(t1)
        {
            prod=t1->data * t2->data + carry;
            insert_at_first(&temp1_h, &temp1_t, prod % 10);
            carry=prod / 10;

            t1=t1->prev;
        }

        if (carry) insert_at_first(&temp1_h, &temp1_t, carry);

        for (int i=0; i<count; i++)
        {
            insert_at_last(&temp1_h, &temp1_t, 0);
        }

        if (temp2_h == NULL)
        {
            temp2_h=temp1_h;
            temp2_t=temp1_t;
        }
        else
        {
            Dlist *new_h = NULL;
            Dlist *new_t = NULL;

            addition(temp2_t, temp1_t, &new_h, &new_t);

            delete_list(&temp2_h, &temp2_t);
            delete_list(&temp1_h, &temp1_t);

            temp2_h=new_h;
            temp2_t=new_t;
        }

        count++;

        t2=t2->prev;

        temp1_h=NULL;
        temp1_t=NULL;
    }

    *headR=temp2_h;
    *tailR=temp2_t;

    return SUCCESS;
}