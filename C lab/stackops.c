#include <stdio.h>

void main()
{
	int top=-1;
	int limit,option;
	printf("enter the limit of stack:");
	scanf("%d",&limit);
	int stack[limit];
	while(option!=4)
	{
	printf("\n***choose an option***\n1.add members to stack\n2.remove members from stack\n3.display stack\n4.end program: ");
	scanf("%d",&option);

	if (option==1)
	{
		for(int i=0;i<limit;i++)
		{
		if (top<limit)
		{
			printf("\nenter stack member:");
			scanf("%d",&stack[top+1]);
			top++;
		}
		else	
		{
			printf("\nStack overflow");
		}
	
		}
	}
	else if(option==2)
		{
		if (top>=0)
			{top--;}
		else
		printf("stack under flow");
	}
	else if(option==3)
	{	
		for (int i=0;i<top+1;i++)
		{
			printf("%d",stack[i]);
		}	
	}

	}
}
		



























