import java. io.*;

class armstrong{

public static void main (String[]args)
{

int number = 371, n,remainder,result =0;

n=number;

while(n!=0)
{
 remainder = n% 10;
 result += Math.pow(remainder,3);
 n/=10;
 }
 if(result == number)
 System.out.println(number + " is an armstrong number. ");
 else
 System.out.println(number + " is not a armstrong number. ");
 }
 }