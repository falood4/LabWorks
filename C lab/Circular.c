#include<stdio.h>
#include<stdlib.h>

int cqueue[10];
int front=-1;
int rear=-1;


int isEmpty()
{
        if(front==-1)
                return 1;
        else
                return 0;
}

int isFull()
{
        if((front==0 && rear==9) || (front==rear+1))
                return 1;
        else
                return 0;
}

void insert(int item)
{
        if(isFull())
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if(front == -1 )
                front=0;

        if(rear==9)
                rear=0;
        else
                rear=rear+1;
        cqueue[rear]=item ;
}

int del()
{
        int item;
        if(isEmpty())
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=cqueue[front];
        if(front==rear) 
        {
                front=-1;
                rear=-1;
        }
        else if(front==9)
                front=0;
        else
                front=front+1;
        return item;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        return cqueue[front];
}

void display()
{
        int i;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i=front;
        if( front<=rear )
        {
                while(i<=rear)
                        printf("%d ",cqueue[i++]);
        }
        else
        {
                while(i<=10)
                        printf("%d ",cqueue[i++]);
                i=0;
                while(i<=rear)
                        printf("%d ",cqueue[i++]);
        }
        printf("\n");
}

int main()
{
        int choice,item,limit;
        while(1)
        {
                printf("\n1.Insert 2.Delete 3.Peek 4.Display 5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1 :
			printf("Enter no. of elments to enter");
  			scanf("%d", &limit);
			for(int i=0;i<limit;i++){
                        printf("\nInput the element: ");
                        scanf("%d",&item);
                        insert(item);}
                        break;
                case 2 :
                        printf("\nElement deleted is : %d\n",del());
                        break;
                case 3:
                        printf("\nElement at the front is  : %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}

