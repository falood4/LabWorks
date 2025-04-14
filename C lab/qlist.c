#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *front;
struct node *rear;

void enq(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr==NULL)
    {
        printf("\nOverflow error");
        return;
    }

    ptr->info=item;
    ptr->next=NULL; 

    if (front==NULL) 
	{
	    front=rear=ptr;
	}
    else 
	{
	
    	rear->next=ptr;
    	rear=ptr;
	}

}

void dq()
{
    if (front==NULL)
    {
        printf("\nUnderflow error");
        return;
    }

    front=front->next;
}

int display()
{
    if (front==NULL)
    {
        printf("\nQueue is empty");
	return 0;
    }

    struct node *ptr=front;

    printf("\nQueue: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    int limit, option, item;

    while (option != 4)
    {
        printf("\n***Choose an option***\n1. Enqueue\n2. Dequeue\n3. Display \n4. End program\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
	        printf("Enter the no. of elements to enter: ");
    		scanf("%d", &limit);
		for(int i=0;i<limit;i++)
		{
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enq(item);
		}
                break;

        case 2:
            dq();
            break;
	    
        case 3:
            display();
            break;

        case 4:
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

