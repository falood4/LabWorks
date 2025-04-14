import java.io.*;
import java.util.*;
import java.lang.Math;

class Area {
    public int area(int side) {
        return side * side;
    }

    public int area(int l, int b) {
        return l * b;
    }

    public float area(float s1, float s2, float s3) {
        float s = (s1 + s2 + s3) / 2;
        float area = (float)Math.sqrt(s * (s - s1) * (s - s2) * (s - s2));
        return area;
    }

    public static void main(String args[]) {
        Area calc = new Area();

        System.out.println("Enter side of square:");
        Scanner io = new Scanner(System.in);
        int a = io.nextInt();
        int result = calc.area(a);
        System.out.println("Area of square = " + result);

        System.out.println("Enter sides of rectangle:");
        int length = io.nextInt();
        int breadth = io.nextInt();
        result = calc.area(length, breadth);
        System.out.println("Area of rectangle = " + result);

        System.out.println("Enter sides of triangle:");
        float n1 = io.nextFloat();
        float n2 = io.nextFloat();
        float n3 = io.nextFloat();
        float result_tri = calc.area(n1, n2, n3);
        System.out.println("Area of triangle = " + result_tri);
    }
}
