

#include "apc.h"

int validate_number_of_CLA(int argc){
    
    if(argc != 4) return FAILURE;
    return SUCCESS;
}

int validate_input(char *argv[]){

    int i=0;
    while(argv[1][i]){
        if(argv[1][i] < '0' || argv[1][i] > '9') return FAILURE;
        i++;
    }

    i=0;
    while(argv[3][i]){
        if(argv[3][i] < '0' || argv[3][i] > '9') return FAILURE;
        i++;
    }

    if (argv[2][0] != '+' &&
        argv[2][0] != '-' &&
        argv[2][0] != '*' &&
        argv[2][0] != '/')
        return FAILURE;

    return SUCCESS;

}

int slicing_input(char *argv[], Dlist **head1, Dlist **tail1,
                  Dlist **head2, Dlist **tail2)
{
    int i=0;
    int digit;
    while (argv[1][i])
    {
        digit=argv[1][i] - '0';
        insert_at_last(head1, tail1, digit);
        i++;
    }

    i=0;
    while (argv[3][i])
    {
        digit=argv[3][i] - '0';
        insert_at_last(head2, tail2, digit);
        i++;
    }

    return SUCCESS;

}