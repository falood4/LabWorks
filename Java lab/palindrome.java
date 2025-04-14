import java.io.*;

class palindrome{
	public static void main(String args[]){
		int a=12321;
		int temp,n,check;
		check=0;
		temp=a;
		while(temp>0)
		{
			n=temp%10;
			check=(check*10)+n;
			temp=temp/10;
		}
		if (check==a)
			System.out.println("12321 is a palindrome");
		else
			System.out.println("12321 is not a palindrome");
	}
}