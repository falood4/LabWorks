import java.io.*;

class pal{

public static void main(String[]args)
{

int num=101;
int temp,sum=0,i;

temp=num;

while (num>0){
i=num%10;
sum=sum*10+i;
num=num/10;
}

if(temp==sum)
System.out.print(temp +" is palindrome");

else
System.out.print(temp +" is not palindrome");
}
}