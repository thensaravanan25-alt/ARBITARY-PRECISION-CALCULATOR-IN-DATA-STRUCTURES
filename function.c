#include "dll.h"

// count the digits in the list 

int count (Node *head)
{
    int c=0;
    while ( head)
    {
        c++;
        head = head -> next;
    }
    return c;
}

// compare the digits in the list 

int compaare_digits ( Node *head , Node *head2 )
{
    

    while ( head && head2)
    {
        if ( head-> data > head2-> data)

          return 1;

        else if(head -> data < head2 -> data)

          return -1;

        head =  head-> next;
        head2 = head2 -> next; 
    }
    return 0;
}
int compare_list_fun( Node *head , Node *tail , Node *head2 , Node *tail2  )

        {
             int flag =0;
            int res1 = count(head);
            int res2 = count( head2);
        
             if ( res1 > res2 )
             {
                 // printf("\n Head1 called first "); 
                  return 1;
             }
             else if ( res1 < res2)

             {
                // printf("\nHead 2 called first");
                flag = 1;
                 return -1;
             }
             else
             {
                int res = compaare_digits( head , head2);
                if ( res > 0  )
                {
                    return 1 ;
                }
                else if ( res < 0)
                {
                    flag = 1;
                    return -1;
                }
                else
                {
                    return 0;
                }
               
             }
        }