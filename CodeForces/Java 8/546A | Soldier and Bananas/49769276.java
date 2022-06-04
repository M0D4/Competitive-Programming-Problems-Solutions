import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k=sc.nextInt();//cost of 1st banana
        int n=sc.nextInt();//initial number of dollars the soldier has
        int w=sc.nextInt();//number of bananas he want
        int sum=0;
        n -=k;
        for (int i = 1; i < w; i++) {
            if(n -((i+1)*k)>=0) n -= (i+1)*k;
            else {
                sum += (i+1)*k-n;
                n=0;
            }
        }
        System.out.println(sum);
    } //end main method
   } //end class