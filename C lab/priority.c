#include<stdio.h>

int front = -1,rear = -1,i,j;
void bubsort();
void enqueue(int,int);
int dequeue();
void display();

struct priorityqueue
{
int elem;
int prior;
}pq[10],temp;

int main()
{
int ch,e,p;
int flag=1;
do
{
printf("\n1) Enqueue\n 2) Dequeue\n 3) Display\n 4) Exit\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf ("\nEnter the element to insert : ");
	scanf("%d", &e);
	printf ("Enter priority : ");
	scanf("%d", &p);
	enqueue(e,p);
	break;
case 2:
	bubsort();
	dequeue();
	break;
case 3:
	bubsort();
	display();
	break;
case 4:
	flag=0;
	break;
default:
	printf("wrong choice");
	break;
}
}while (flag!=0);
return 0;
}




void enqueue(int element, int priority)
{
if (rear<10)
	{
	if (front==-1)
		front=0;

	rear++;
	pq[rear].elem=element;
	pq[rear].prior=priority;
	}
}

int dequeue()
{
int element;
if (front==-1 && rear==-1)
	printf("\n underflow \n");

else
{
element = pq[front].elem;
	if (front==rear)
	{
		front=-1; rear=-1;
	}
	else
	{
		front++;
	}
		printf("Deleted element : %d \n", element);
}
}

void bubsort()
{
for (i = front; i <=rear; i++)
	{
	for (j = front; j <=rear; j++)
		{
			if (pq[i].prior < pq[j].prior)
			{
				temp=pq[i];
				pq[i]=pq[j];
				pq[j]=temp;
			}	
		}
	}
}


void display()
{
int i;
if (front==-1)
	{
	printf("Empty Queue\n");
	}
else
	{
	for (i=front; i<=rear; i++)
		{
		printf("%d[%d] ", pq[i].elem, pq[i].prior);
		}
	}
}
