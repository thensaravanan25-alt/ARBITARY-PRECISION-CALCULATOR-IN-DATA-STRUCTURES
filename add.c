#include "dll.h"

int insert_first( Node **headR , Node **tailR , int num)
{

    Node *new_node ;
    new_node = malloc(sizeof(Node));
    new_node -> data = num; 
    new_node -> prev = NULL;
    new_node -> next = NULL;

    if ( *headR == NULL)
    {
        *headR = *tailR = new_node;
         return SUCCESS;
    }
    
     new_node -> next = *headR;
     (*headR) -> prev =  new_node;
     *headR = new_node;
     return SUCCESS;
  

}

int print_node (Node *headR)
  {

    Node *temp = headR;

    printf("\n---- Result  ------ \n");

    printf("Head <-> ");

    while (temp )
    {
        if(temp-> data == -1)
        {
            printf("-");
        }

        else
        {
            printf("%d <-> " , temp -> data);
        }

         temp = temp-> next;
        
    }
    printf("Tail\n"); 
}


int add_function (Node **head , Node **tail , Node **head2 , Node **tail2 , Node **headR , Node **tailR)
{

   // printf("\nInside the addition funtion\n");

   *headR = NULL;
   *tailR = NULL;
   
    Node *temp1 = *tail;
    Node *temp2 = *tail2;
    
     
    int res;
    int carry = 0;

 while ( temp1 != NULL || temp2 != NULL)
 {
      if ( temp1 != NULL && temp2 == NULL)
      {
        res = temp1 -> data + 0 + carry;
        carry = 0;
        if ( res > 9)
        {
            carry = 1;
            res = res % 10;
        }
        
        insert_first(headR , tailR , res);
        temp1 = temp1-> prev;

      }
      else if ( temp1 == NULL && temp2 !=NULL)
    {
        res =  0 + temp2-> data  + carry;
        carry = 0;

        if ( res > 9)
        {
            carry = 1;
            res = res % 10;
        }
        insert_first(headR , tailR , res);
        temp2 = temp2-> prev;
    }
     else
    {
        res = temp1 -> data + temp2 -> data + carry;
        carry = 0;
        if (res > 9)
        {
            carry =1;
            res = res % 10;
        }
       
        insert_first(headR , tailR ,res );
        temp1 = temp1-> prev;
        temp2 = temp2-> prev;
        
    }

 }
 if ( carry == 1)
        {
            insert_first (headR , tailR , carry);
        }

   
 }
  



