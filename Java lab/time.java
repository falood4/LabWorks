import java.io.*;
import java.util.*;

class Time{
    Time(int h){
        System.out.println(h+":0:0");
    }
    Time(int h, int m){
        System.out.println(h+":"+m+":0");
        
    }
    Time(int h,int m,int s){
        System.out.println(h+":"+m+":"+s);
        
    }
    public static void main(String args[]){
         Scanner sc=new Scanner(System.in);
         System.out.print("enter time:");
         int h=sc.nextInt();
         int m=sc.nextInt();
         int s=sc.nextInt();
        Time a1=new Time(h);
        Time a2=new Time(h,m);
        Time a3=new Time(h,m,s);
    }
}