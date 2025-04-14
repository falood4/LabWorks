#include<stdio.h>

void linear(int a[30], int key, int limit)
{
for (int i=0;i<limit;i++)
	{
	if (a[i]==key)
		{
		printf("Linear result: %d found at %d", key, i+1);
		break;
		}
	}
}

void binary(int a[30], int key, int limit)
{
int mid;
int lo=0;
int hi=limit-1;
while(lo<=hi)
	{
	mid=(lo+hi)/2;
	if(a[mid]==key)
		{printf("\nBinary result: element found at %d", mid+1);
		break;}
	else if(a[mid]<key)
		{
		lo=mid+1;
		}
	else if(a[mid]>key)
		{
		hi=mid-1;
		}
	}
}

int main()
{
int list[30], val, lim;
printf("enter no. of values you want to enter:");
scanf("%d",&lim);
printf("\nenter values:");
for (int j=0;j<lim;j++)
	{
	scanf("%d",&list[j]);
	}
printf("\nenter value to search:");
scanf("%d", &val);

linear(list,val,lim);
binary(list, val, lim);
}






















	
