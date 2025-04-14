import java.io.*;
import java.util.*;

class Static{
	static int a=9;
	
	static void square(){
		System.out.println("Square="+ (a*a));
	}
	
	static void cube(){
		System.out.println("Square="+ (a*a*a));
	}
	
	public static void main(String args[]){
		System.out.println("Static value="+a);
		Static kur=new Static();
		kur.square();
		kur.cube();
	}
}