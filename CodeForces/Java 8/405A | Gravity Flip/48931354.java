import java.util.Arrays;
import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
                int a[]=new int[sc.nextInt()];
                for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
             Arrays.sort(a);
             for (int i : a) {
                 System.out.print(i+" ");
        }
             System.out.println("");
    } //end main method
 } //end class