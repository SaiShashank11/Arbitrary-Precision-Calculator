
#include "apc.h"

int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR){

    if(tail1 == NULL && tail2 == NULL) return LIST_EMPTY;

    Dlist *t1=tail1;
    Dlist *t2=tail2;
    int carry=0;

    while(t1 || t2){
        int digit1=0;
        int digit2=0;

        if(t1) digit1=t1->data;

        if(t2) digit2=t2->data;

        int sum=digit1 + digit2 + carry;
        insert_at_first(headR, tailR, sum % 10);
        carry=sum / 10;

        if(t1) t1=t1->prev;
        if(t2) t2=t2->prev;

    }
    if(carry) insert_at_first(headR, tailR, carry); 
    
    return SUCCESS;

}