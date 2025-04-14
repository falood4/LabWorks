import java.io.*;
import java.util.*;

class test1 extends Thread
{
	public void run()
	{
		Hello t1 = new Hello();
		t1.start();
		World t2 = new World();
		t2.start();
	}
}

class Hello extends Thread
{
	public void run()
	{
		for(int i=0;i<=10;i++)
		{
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e)
			{
			System.out.println(e);
			}
		System.out.println("Hello");
		}
	}
}

class World extends Thread
{
	public void run()
	{
		for(int i=0;i<=10;i++)
		{
			try
			{
				Thread.sleep(3000);
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
		System.out.println("World");
		}
	}
}

class threadtest
{
	public static void main(String args[])
	{
		test1 t1 = new test1();
		t1.start();
	}
}