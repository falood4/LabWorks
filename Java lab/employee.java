import java.io.*;
import java.util.*;

class info{
	int empid;
	String EmpName;
	String Dept;
	String desg;
	int salary;
	
	public void set(){
		Scanner io=new Scanner(System.in);
		System.out.print("Enter employee id:");
		empid=io.nextInt();
		System.out.print("Enter employee name:");
		EmpName=io.next();
		System.out.print("Enter employee Department:");
		Dept=io.next();
		System.out.print("Enter employee designation:");
		desg=io.next();
		System.out.print("Enter employee salary:");
		salary=io.nextInt();
	}
	public void get(){
		System.out.print("employee id:"+empid+"\t");
		System.out.print("employee name:"+EmpName+"\t");
		System.out.print("employee Department:"+Dept+"\t");
		System.out.print("employee designation:"+desg+"\t");
		System.out.print("employee salary:"+salary+"\t");
		System.out.println("");
	}
}
	
class emp{
	public static void main(String arg[]){
		Scanner io=new Scanner(System.in);
		System.out.print("Enter no. of employees");
		int n=io.nextInt();
		info arr[]=new info[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new info();
		}
		
		for(int i=0;i<n;i++)
		{	
			System.out.println("Enter employee "+(i+1)+" info");
			arr[i].set();
		}
		for(int i=0;i<n;i++)
		{
			arr[i].get();
		}
	}
}