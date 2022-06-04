import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        long n=sc.nextInt() , //number of Oranges
        b=sc.nextInt() , //maximum size of Orange
        d=sc.nextInt(),  //maximum waste
        times=0, 
        sum=0; 
                for (int i = 0; i < n; i++) {
            int a=sc.nextInt();
            if(a<=b) sum +=a;
            if(sum>d){
                times++;
                sum=0;
            }
        }
       System.out.println(times);
                   }//end main method
    }//end class