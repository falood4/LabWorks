import java.io.*;

class prime{

public static void main(String[]args)
{
int i,a=5;
int flag=0;
for(i=2;i<a;i++){
if (a%i==0){
flag=1;
}}
if(flag==0){
System.out.print("is prime");}
else{
System.out.print("not prime");
}
}
} 

