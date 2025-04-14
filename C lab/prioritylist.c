#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    int pr;
    struct node *next;
};

struct node *front;
struct node *rear;
struct node *temp;

void enq(int item, int order)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOverflow error");
        return;
    }

    ptr->info = item;
    ptr->pr = order;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dq()
{
    if (front == NULL)
    {
        printf("\nUnderflow error");
        return;
    }

    struct node *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    struct node *ptr = front;
    for (temp = front; temp != NULL; temp = temp->next)
    {
        for (ptr = front; ptr->next != NULL; ptr = ptr->next)
        {
            if (ptr->pr > ptr->next->pr)
            {
                int tempInfo = ptr->info;
                int tempPriority = ptr->pr;

                ptr->info = ptr->next->info;
                ptr->pr = ptr->next->pr;

                ptr->next->info = tempInfo;
                ptr->next->pr = tempPriority;
            }
        }
    }

    printf("\nQueue: ");
    printf("\nElement:\tPriority: \n");
    ptr = front;
    while (ptr != NULL)
    {
        printf("%d\t\t%d\n", ptr->info, ptr->pr);
        ptr = ptr->next;
    }
}

int main()
{
    int limit, option, item, order;
    while (option != 4)
    {
        printf("\n***Choose an option***\n1. Enqueue\n2. Dequeue\n3. Display \n4. End program\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
                printf("Enter the no. of elements: ");
    		scanf("%d", &limit);
                for (int i=0;i<limit;i++)
		{                
		    printf("Enter item to enqueue: ");
                    scanf("%d", &item);
                    printf("Enter priority:");
                    scanf("%d", &order);
                    enq(item, order);
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

