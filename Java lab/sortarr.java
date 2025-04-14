import java.io.*;

class Main {
    public static void main(String args[]) {
        int[] arr = {2,6,3,4,9};
		BubbleSort bub=new BubbleSort();
		bub.sort(arr);
		for(int i=0;i<6;i++)
			System.out.println(" "+arr[i]);
    }
}

class BubbleSort {
    public static void sort(int[] arr){
		int temp=0;
        for (int i=0; i<arr.length-1; i++){
            for (int j=0; j<arr.length-i-1; j++){ 
                if (arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

}
