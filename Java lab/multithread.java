import java.util.Random;

public class multithread {
    public static void main(String[] args) {
        one o=new one();
        o.start();
    }
}

class one extends Thread{
    int a;
    public void run() {
        Random rand = new Random();
        
        
        while (true) {

            a=rand.nextInt(100);
			System.out.println(a);
            if(a%2==0){
				two o2=new two(a);
				//o2.sqr(a);
                o2.start();
            }else{
				three o3=new three(a);
				//o3.cub(a);
                o3.start();
            }
            try {
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}
class two extends Thread{
	int n;
	two(int n){
		this.n=n;
	}
    public void run(){
        System.out.println(n*n);
    }

}
class three extends Thread{
	int n;
	three(int n){
		this.n=n;
	}
    public void run(){
        System.out.println(n*n*n);
    }
}