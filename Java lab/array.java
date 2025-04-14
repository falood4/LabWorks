import java.io.*;
import java.util.Scanner;

class arr{
	public static void main(String args[]){
		int[] array=new int[6];
		Scanner myObj = new Scanner(System.in);
		for(int i=0;i<6;i++){
			System.out.println("enter a number:");
			int n = myObj.nextInt();
			array[i]=n;
		}
		for(int i=5;i>=0;i--)
			System.out.println(" "+array[i]);
	}
}