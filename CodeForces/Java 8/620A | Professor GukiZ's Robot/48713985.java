import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a1=sc.nextInt();
        int a2=sc.nextInt();
        int b1=sc.nextInt();
        int b2=sc.nextInt();
        int steps =Math.max((Math.abs(a1-b1)),Math.abs(a2-b2));
        System.out.println(steps);
    } //end main method
 } //end class