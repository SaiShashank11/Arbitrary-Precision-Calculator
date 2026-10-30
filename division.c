
#include "apc.h"

int compare_lists(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;

        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}


int division(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *head1 = tail1;
    Dlist *head2 = tail2;

    Dlist *tempH = NULL;
    Dlist *tempT = NULL;

    int count;

    /* Move tail1 to head */
    while (head1->prev)
        head1 = head1->prev;

    /* Move tail2 to head */
    while (head2->prev)
        head2 = head2->prev;

    /* Division by zero */
    if (head2->data == 0)
        return FAILURE;

    while (head1)
    {
        /* Bring down one digit */
        insert_at_last(&tempH, &tempT, head1->data);

        count = 0;

        /* Keep subtracting divisor */
        while (compare_lists(tempH, head2) >= 0)
        {
            Dlist *subH = NULL;
            Dlist *subT = NULL;

            subtraction(tempT, tail2, &subH, &subT);

            delete_list(&tempH, &tempT);

            tempH = subH;
            tempT = subT;

            count++;
        }

        /* Count is the quotient digit */
        insert_at_last(headR, tailR, count);

        head1 = head1->next;
    }

    /* Remove leading zeroes from quotient */
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    delete_list(&tempH, &tempT);

    return SUCCESS;
}