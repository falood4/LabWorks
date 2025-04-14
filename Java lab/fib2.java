import java.io.*;
import java.util.*;

class Fib{

	public void nonrecur(int n){
		int n1 = 0, n2 = 1;
		for(int i=0;i<n;i++){
			System.out.print(n1+" ");
			int n3=n1+n2;
			 n1=n2;
			 n2=n3;
			}
		}
		
	public int recur(int n){
		if (n<=1){
			return n;
		}
		return recur(n-1)+recur(n-2);
		}
	}
	public static void main(String args[]){
		Fib kur=new Fib();
		Scanner io=new Scanner(System.in);
		int a=io.nextInt();
		System.out.println("Non-Recursive");
		kur.nonrecur(a);
		int p=kur.recur(a);
		System.out.println("Recursive"+p);
	}
}