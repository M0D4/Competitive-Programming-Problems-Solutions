import java.util.Scanner;
 public class Test2 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int x=sc.nextInt();
        int c=0;
        for (int i = 1; i <=a; i++) {
            if(x%i==0 && x/i<=a)c++;
        }
        System.out.println(c);
    }//end main method
 }//end class