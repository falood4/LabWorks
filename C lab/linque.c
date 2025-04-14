#include<stdio.h>

void enq(int q[],int item,int*rear,int n)
{
if(*rear==n-1)
	{
	printf("Overflow error\n");
	}
else
	{
	(*rear)++;
	q[*rear]=item;
	}
}

void deq(int q[],int *rear,int *front)
{
if(*front>*rear)
	{
printf("Underflow error\n");
	}
else
	{
	int data=q[*front];
	(*front)++;
	printf("Deleted item is%d\n",data);
	}
}

void display(int q[],int front,int rear)
{
for(int i=front;i<=rear;i++)
	{
	printf("%d",q[i]);
	}
	printf("\n");
}

void main()
{
int queue[15];
int rear=-1;
int front=0;
int option,item;

printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
scanf("%d",&option);

while(option!=4)
{
if(option==1)
	{
	if(rear<14)
	{
		printf("Enter value:");
		scanf("%d",&item);
		enq(queue,item,&rear,15);
	}
	else
	{
		printf("Overflow error\n");
	}
}

else if(option==2)
{
	deq(queue,&rear,&front);
}

else if(option==3)
{
	display(queue,front,rear);
}

printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
scanf("%d",&option);
}

}
