#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *top = NULL;

void push(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nOverflow error");
        return;
    }

    ptr->info = item;
    ptr->next = top;
    top = ptr;
}

void pop()
{
    if (top == NULL)
    {
        printf("\nUnderflow error");
        return;
    }

    struct node *ptr = top;
    int item = ptr->info;

    top = top->next;
    free(ptr);

    printf("Popped element: %d\n", item);
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    struct node *ptr = top;

    printf("\nStack: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int limit, option, item, count;
      	
    while (option != 4)
    {
        printf("\n***Choose an option***\n1. Add members to stack\n2. Remove members from stack\n3. Display stack\n4. End program\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
	        printf("Enter the no. of elements to push: ");
    		scanf("%d", &limit);	
	        for(int i=0;i<limit;i++)
		{
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
		count++;
		}
                break;

        case 2:
            pop();
	    count--;
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

