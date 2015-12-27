#include<stdio.h>
#include<string.h> //for string length
#include<stdlib.h> //for malloc function

//define structure of the node
struct node{
	char c;
	struct node *next;
	
};

int main()
{   
    int count,length,i;
	struct node* head =NULL;
	struct node* tail = NULL;
	
    char p[50];
	printf("\n Enter a string : ");
	scanf("%s",p);
    length = strlen(p);
   
    //define a # node for stuffing it at the beginning of the string
    struct node* temp1 = (struct node *)malloc(sizeof(struct node));
	temp1->c = '#';
	temp1->next = NULL;
	head = temp1; // initialise head and tail to it
    tail=temp1;
   
    
    i=0;
	while(i < length)
	{
			
			struct node *temp = (struct node *)malloc(sizeof(struct node));
            tail->next = temp;
            temp->c = p[i];
            temp->next = NULL;
			tail = temp;
	        i++;
            	
	}

    //define a # node for stuffing it at the ending of the string
	struct node *temp2 = (struct node *)malloc(sizeof(struct node));
	temp2->c = '#';
	temp2->next = NULL;
	tail->next = temp2;
	tail=temp2;

     
    // now we will stuff $ infront of $ or # tht might be present in the data
	struct node *train, *prev;
	train= head;
    prev = head;
   //first traverse the first node then we will cross the first # 
	train = train->next;
    count = 1 ; //since first node is traversed we add 1 to count

	while(train->next != NULL)
	{  
		if(train->c == '$' || train->c == '#' )
			{
				struct node* insert = (struct node * )malloc(sizeof(struct node));
				insert->c = '$';
                prev->next = insert;
                insert->next = train;
                prev = insert;
                train = train->next;
                prev = prev->next;
				count += 2; // if $ or  # we insert another $ before it so count is increased by 2
				 	
			}
		
		else
            {   prev = prev->next;
                train = train->next;
                count += 1;

            }
		
		
		}

    printf("\n Before the packet is handed over to data link layer the data is : ");
     printf("%s",p);
    
	printf("\n After the packet is handed over to data link layer the data is stuffed as : ");
    struct node* printit;
    printit = head;
    i = 0;
    	while(i <= count)
	{   
	        printf("%c",printit->c);
            printit = printit->next;
             	i++;
    }
	
    // free all the nodes
    struct node * freeit;
    freeit = head;
    while(head != NULL)
    {
        head = head->next;
        free(freeit);
        freeit = head;

    }
    free(head);
    

return 0;	
	
	
}
