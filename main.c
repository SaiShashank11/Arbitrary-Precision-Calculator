#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    if(validate_number_of_CLA(argc) == FAILURE)
    {
        printf("ERROR: Invalid number of arguments\n");
        return FAILURE;
    }

    if(validate_input(argv) == FAILURE)
    {
        printf("ERROR: Invalid input\n");
        return FAILURE;
    }

    slicing_input(argv, &head1, &tail1, &head2, &tail2);

    switch(argv[2][0])
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            printf("First number: ");
            print_list(head1);

            printf("Second number: ");
            print_list(head2);
            break;

        case '-':
            subtraction(tail1, tail2, &headR, &tailR);
            printf("First number: ");
            print_list(head1);

            printf("Second number: ");
            print_list(head2);
            break;

        case '*':
            multiplication(tail1, tail2, &headR, &tailR);
            printf("First number: ");
            print_list(head1);

            printf("Second number: ");
            print_list(head2);
            break;

        case '/':
            division(tail1, tail2, &headR, &tailR);
            printf("First number: ");
            print_list(head1);

            printf("Second number: ");
            print_list(head2);
            break;

        default:
            printf("Use +, -, *, / operators only\n");
            break;
    }

    printf("Result: ");
    print_list(headR);

    return SUCCESS;
}