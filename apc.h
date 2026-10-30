#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

int validate_number_of_CLA(int argc);
int validate_input(char *argv[]);
int slicing_input(char *argv[], Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

int insert_at_first(Dlist **head, Dlist **tail, int data);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);

int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int division(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int compare_lists(Dlist *head1, Dlist *head2);


#endif