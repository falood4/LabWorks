public abstract class Shape {
  int a, b;
  abstract void printArea();
}

class Circle extends Shape {
    public Circle(int radius) { 
        this.a = radius;
        this.b = radius; 
    }

    void printArea() {
        System.out.println("Area of circle: " + (3.14159 * a * a));
    }
}

class Triangle extends Shape{
    Triangle(int a, int b)
    {  
        this.a=a;
        this.b=b;
    }
    void printArea(){
        System.out.println("Area of triangle"+(0.5*a*b));
    }
}
class Rectangle extends Shape{
    Rectangle(int a, int b)
    {   
        this.a=a;
        this.b=b;
    }
    void printArea(){
        System.out.println("Area of rectangle"+(a*b));
    }
}

public class Main{
    public static void main(String args[]){
        Rectangle rect=new Rectangle(5,6);
        Circle round=new Circle(8);
        Triangle tri=new Triangle(3,6);
        rect.printArea();
        round.printArea();
        tri.printArea();

    }
}