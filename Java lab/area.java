import java.io.*;
import java.util.*;

class rectangle {
    int length;
    int breadth;

    rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    public void display() {
        System.out.println("length: "+length+"\tbreadth: "+breadth);
    }

    public void area() {
        int a=length*breadth;
        System.out.println("Area: "+a);
    }

    public static void main(String[] args) {
		Scanner io=new Scanner(System.in);
		System.out.println("enter length and breadth");
		int l=io.nextInt();
		int b=io.nextInt();
        rectangle rect=new rectangle(l, b);
        rect.display();
        rect.area();
	}
}