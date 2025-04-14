import java.io.*;
import java.util.*;

class ini{
	int val=9;
	
	class check{
		void checker(){
			if (val%2==0)
			System.out.println(val+" is even");
		else
			System.out.println(val+" is odd");
	}
}
	public static void main(String arg[]){
		ini n=new ini();
		ini.check test= n.new check();
		System.out.println("outer class value="+n.val);
		test.checker();
	}
}