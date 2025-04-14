import java.io.*;
import java.util.*;

class fibo
{
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the nth term to find fibonacci of:");
	int num = sc.nextInt();
	fibo f1= new fibo();
	fibo f2= new fibo();
	
	//non recursive
	System.out.println("fibo series upto nth value(non recursive):");
	f1.fibonr(num);
	System.out.println();
	//recursive
	System.out.println("fibo series upto nth value(recursive):");
	int i;
	for (i = 0; i < num; i++)
	{
      System.out.print(fibor(i) + " ");
    }
	System.out.println();
	System.out.print("nth value is "+fibor(i-1));
}

void fibonr(int count)
{
	int n=0,n1=1,n2,i;
	for(i=0;i<count;i++)
	{
		System.out.print(" "+n);
		n2=n+n1;
		if(i==count-1)
		{
		System.out.println();
		System.out.println("nth value is "+n);
		}
		n=n1;
		n1=n2;
	}

}

static int fibor(int count)
{
	if (count == 0)
	{
      return 0;
    }

    if (count == 1 || count == 2)
	{
      return 1;
    }
    return fibor(count - 1) + fibor(count - 2);
}
}