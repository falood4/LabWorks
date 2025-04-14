import java.io.*;
import java.util.*;

class Person {
    String name;
    int age;
    char gender;
}

class Student extends Person {
    int mark1, mark2, mark3, total;
    char grade;

    public void set() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name:");
        name = sc.nextLine();
        System.out.print("Enter student age:");
        age = sc.nextInt();
        System.out.print("Enter student gender:");
        gender = sc.next().charAt(0);
        System.out.print("Enter student mark1:");
        mark1 = sc.nextInt();
        System.out.print("Enter student mark2:");
        mark2 = sc.nextInt();
        System.out.print("Enter student mark3:");
        mark3 = sc.nextInt();
    }

    public void get() {
        total = mark1 + mark2 + mark3;
        System.out.print("name:" + name + "\t");
        System.out.print("age:" + age + "\t");
        System.out.print("gender:" + gender + "\t");
        System.out.print("mark1:" + mark1 + "\t");
        System.out.print("mark2:" + mark2 + "\t");
        System.out.print("mark3:" + mark3 + "\t");
        System.out.println("Total marks:" + total);
        if (total > 150) {
            if (total > 270) {
                System.out.println("Grade:A");
            } else if (total > 240) {
                System.out.println("Grade:B");
            } else if (total > 210) {
                System.out.println("Grade:C");
            } else if (total > 180) {
                System.out.println("Grade:D");
            } else {
                System.out.println("Grade:P");
            }
        } else {
            System.out.println("Grade:??");
        }
    }

    public static void main(String args[]) {
        Student[] stud = new Student[4];

        for (int i = 0; i < 4; i++) {
            stud[i] = new Student();
            System.out.println("Enter student " + (i + 1) + " info"); 
            stud[i].set();
        }

        for (int j = 0; j < 4; j++) {
            stud[j].get();
        }
    }
}
