import java.io.*;
import java.util.*;

class info{
	int ID_number;
	String AccHolder;
	int balance;
	
	public void set(){
		Scanner io=new Scanner(System.in);
		System.out.print("Enter account id:");
		ID_number=io.nextInt();
		System.out.print("Enter holder name:");
		AccHolder=io.next();
		System.out.print("Enter bank balance:");
		balance=io.nextInt();
	}
	public void get(){
		System.out.print("account id:"+ID_number+"\t");
		System.out.print("holder name:"+AccHolder+"\t");
		System.out.print("bank balance:"+balance+"\t");
		System.out.println("");
	}
	public void dep(int x)
	{
		balance=balance+x;
	}
	public void reduce(int y)
	{
		balance=balance-y;
	}
}
	
class accentry{
	public static void main(String arg[]){
		Scanner io=new Scanner(System.in);
		System.out.print("Enter no. of accounts");
		int n=io.nextInt();
		info arr[]=new info[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new info();
		}
		
		for(int i=0;i<n;i++)
		{	
			System.out.println("Enter account "+(i+1)+" info");
			arr[i].set();
		}
		for(int i=0;i<n;i++)
		{
			arr[i].get();
		}
		int ch=0;
		while(ch!=4)
		{
			System.out.print("\nEnter choice: 1.Check balance 2.Deposit 3.Withdraw 4.Exit");
			ch=io.nextInt();
			
			switch(ch){
				case 1:
				System.out.print("Enter account ID:");
				int searchID=io.nextInt();
				for(int i=0;i<n;i++)
				{
					if(arr[i].ID_number==searchID)
						System.out.println(arr[i].balance);
				}
				break;
				
				case 2:
				System.out.print("Enter account ID:");
				searchID=io.nextInt();
				for(int i=0;i<n;i++)
				{
					if(arr[i].ID_number==searchID)
					{
						System.out.println("Enter amount to deposit");
						int a=io.nextInt();
						arr[i].dep(a);
						System.out.println("New balance:"+arr[i].balance);
						break;
					}
				}
				break;
				
				case 3:
				System.out.print("Enter account ID:");
				searchID=io.nextInt();
				for(int i=0;i<n;i++)
				{
					if(arr[i].ID_number==searchID)
					{
						System.out.println("Enter amount to withdraw");
						int b=io.nextInt();
						arr[i].reduce(b);
						System.out.println("New balance:"+arr[i].balance);
						break;
					}
				}
				break;
			}
		}
	}
}