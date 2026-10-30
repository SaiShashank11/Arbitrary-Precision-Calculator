#include "apc.h"

int insert_at_first(Dlist **head, Dlist **tail, int data){

    Dlist *new_node=malloc(sizeof(Dlist));

    if(new_node == NULL) return FAILURE;

    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;

    if(*head == NULL){
        *head=new_node;
        *tail=new_node;
        return SUCCESS;
    }

    (*head)->prev=new_node;
    new_node->next=*head;
    *head=new_node;
    
    return SUCCESS;

}

int insert_at_last(Dlist **head, Dlist **tail, int data){

    Dlist *new_node=malloc(sizeof(Dlist));

    if(new_node == NULL) return FAILURE;

    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;

    if(*head == NULL){
        *head=new_node;
        *tail=new_node;
        return SUCCESS;
    }

    new_node->prev=*tail;
    (*tail)->next=new_node;
    *tail=new_node;

    return SUCCESS;

}

int delete_list(Dlist **head, Dlist **tail){

    if(*head == NULL) return LIST_EMPTY;

    Dlist *temp;

    while(*head){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *tail=NULL;

    return SUCCESS;

}

void print_list(Dlist *head){

    if(head == NULL) return;

    else{
        printf("Head -> ");
        while(head){
            printf("%d <-",head->data);
            head=head->next;
            if(head) printf("> ");
        }
        printf(" Tail\n");
    }
}