#include <stdio.h>

int main()
{
int a[10], b[10], n, ch, i,j,k,y, pass,min,tmp, flag;
printf("enter limit of values:");
scanf("%d",&n);
printf("enter values\n");
for (int i=0;i<n;i++)
{
	scanf("%d",&b[i]);
}
flag=1;
while(flag==1)
{
printf("\nSort by \n1.Insertion 2.Selection 3.Bubble 4.Exit: ");
scanf("%d",&ch);
for (i = 0; i < n; i++) 
{ 
        a[i] = b[i];
}
switch(ch)
{
case 1:
	;
	for(j=1;j<n;j++)
	{
		y=a[j];
		i=j-1;
		while(i>=0&&y<a[i])
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=y;
	}
	for (i = 0; i < n; i++) 
		{
			printf("%d ", a[i]);
		}
	break;
case 2:
	
	for(pass=0;pass<n-1;pass++)
	{
		min=pass;
		for(i=pass+1;i<n;i++)
		if(a[i]<a[min])
			min=i;
		if(min!=pass)
		{
			tmp=a[pass];
			a[pass]=a[min];
			a[min]=tmp;
		}
	}
	for (i = 0; i < n; i++) 
	{
		printf("%d ", a[i]);
	}
	break;

case 3:
	for (i=0; i<n-1; i++) 
	    {
		for (j=0; j<n-i-1; j++) 
		{
		    if (a[j] > a[j+1]) 
		    {
		        tmp = a[j];
		        a[j] = a[j + 1];
		        a[j + 1] = tmp;
		    }
		}
	    }

	    printf("Sorted array in ascending order:\n");
	    for (i = 0; i < n; i++) 
	    {
		printf("%d ", a[i]);
	    }
	    break;
case 4:
	flag=0;
}
}
}
