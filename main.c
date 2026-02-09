/*

NAME         :  S.THENMOZHI
DATE         : 2. 02 . 2026
PROJECT      : ARBITARY PRECISION CALCULATOR
INPUT        : THROUGH COMMAND LINES
FUNCTIONS    : ADDITION , SUBTRACTION , MULTIPLICATION  , DIVISION
EXAMPLES     :
 
     1 0 + 1 0
     ANS : 20 

     20 - 10
     ANS : 10

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dll.h" 

int insertend( Node **head  , Node **tail , int data)
{
       // Node *head = NULL;
         Node *newnode;
         newnode = (Node* )malloc(sizeof(Node));
         newnode -> data = data;
         newnode -> next = NULL;
         newnode -> prev = NULL;
         if( *head == NULL )
         {
             
            // list is empty now only adding elemnt
            *tail =  *head = newnode;
             return SUCCESS;
         }
             Node *temp = *head;
            //list is not empty
              newnode -> prev = *tail;
              (*tail) -> next = newnode;
              *tail = newnode;
               return SUCCESS;
            
        }
        
       int flag =0;
int main(int arg , char *argv[])
{
     Node *head  = NULL;
     Node *tail  = NULL;

     Node *head2 = NULL;
     Node *tail2 = NULL;

     Node *headR = NULL;
     Node *tailR = NULL;

    int num, i ;

    // check for list 1 or list 2

    // if the number comes before operator it is list 1 

    // if the number comes after operator it is list 2

    for ( i=1; argv[i] != NULL; i++ )
    {
        int list_no;
       
        if ( strcmp ( argv[i] , "+") == 0|| strcmp ( argv[i] , "-") ==0 || strcmp ( argv[i] , "*")== 0|| strcmp(argv[i] , "/")==0)
          {
           list_no =2;   // stores in list 2
           continue;
          }
        num = atoi (argv[i]);

          if(list_no == 2)
           {
                insertend( &head2 , &tail2 , num) ;
           }
          else
             {
                insertend( &head, &tail , num);
             }
    }

    // print the list 1 and list 2 

    Node *temp = head;

    printf("\n LIST 1 \n");
    printf("\nHead <-> ");

    while (temp != NULL)
    {
        printf("%d <-> " , temp->data);
        temp = temp->next;
    }
    printf("Tail\n");

    Node *temp1 = head2;

    printf("\n LIST 2 \n");
    printf("\nHead <-> ");

    while (temp1 != NULL)
    {
        printf("%d <-> " , temp1->data);
        temp1 = temp1->next;
    }
    printf("Tail\n");
    

/*
    TO FIND WHETHER IT IS ADDITION OR SUBTRACTION OR 
    MULTIPLICATION OR DIVISION 
*/
   
   
    char operator = 0;

/* find operator */
for (i = 1; argv[i] != NULL; i++)
{
    if (strcmp(argv[i], "+") == 0 ||
        strcmp(argv[i], "-") == 0 ||
        strcmp(argv[i], "*") == 0 ||
        strcmp(argv[i], "/") == 0)
    {
        operator = argv[i][0];
        break;
    }
}

headR = NULL;
tailR = NULL;

// use switch operator for selecting the +  - * /
switch (operator)
{
    case '+':
        add_function(&head, &tail, &head2, &tail2, &headR, &tailR);

        print_node(headR);
        break;

    case '-':
    {
        int cmp = compare_list_fun(head, tail, head2, tail2);    //  calling compare list 

        if (cmp == 1)

            subtract_function(&head, &tail, &head2, &tail2, &headR, &tailR);

        else if (cmp == -1)

            subtract_function(&head2, &tail2, &head, &tail, &headR, &tailR);

        else

            insert_first(&headR, &tailR, 0);

        print_node(headR);

        break;
    }

    case '*':
        multiply_function(&head, &tail, &head2, &tail2, &headR, &tailR);

        print_node(headR);

        break;

    case '/':
        division_function(&head, &tail, &head2, &tail2, &headR, &tailR);

        print_node(headR);

        break;

    default:

        printf("Invalid operator\n");
}

  


  

}