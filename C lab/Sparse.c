#include<stdio.h>
void transpose(int sp[][3],int trans[][3])
{
    int i,j,k=1;
    trans[0][0]=sp[0][1];
    trans[0][1]=sp[0][0];
    trans[0][2]=sp[0][2];
    for(i=0;i<sp[0][1];i++)
    {
        for(j=0;j<=sp[0][2];j++)
            if(sp[j][1]==i)
            {
                trans[k][0]=sp[j][1];
                trans[k][1]=sp[j][0];
                trans[k][2]=sp[j][2];
                k++;
            }
    }
    printf("Transpose of matrix: \n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",trans[i][j]);
        }
    printf("\n");
    }
}
void sparse (int d[][100],int r,int c)
{
	int n=0,m=1,i,j,k,b[100][3],trans[100][3];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		if (d[i][j] != 0)
			{
				b[m][0]=i;
				b[m][1]=j;
				b[m][2]=d[i][j];
				n++;
				m++;	
			}	
		k=m;	
		}
		b[0][0]=r;
		b[0][1]=c;
		b[0][2]=n;
	}
	for (i=0;i<k;i++)
	{
		for (j=0;j<3;j++)
			{printf("   %d    ",b[i][j]);}
	printf("\n");
	}
	transpose(b,trans);
}

void main()
{
	int a,b,c[100][100],i,j;
	printf(" enter the number of rows =");
	scanf("%d",&a);
	printf(" enter the number of columns =");
	scanf("%d",&b);
	for (i=0;i<a;i++)
	{
		for (j=0;j<b;j++)
		{printf("enter the elements =");
		scanf("%d",&c[i][j]);}
	}
	for (i=0;i<a;i++)
	{
		for (j=0;j<b;j++)
		{printf("   %d    ",c[i][j]);}
	printf("\n");
	}	
	printf("\n the triplet is \n");
	sparse (c,a,b);
}	
