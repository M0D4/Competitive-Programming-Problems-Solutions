import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         int a=sc.nextInt();
         for (int i = 1; i <=a; i++) {
           if(i%2==0)System.out.print("I love ");
           else System.out.print("I hate ");
           if(i!=a)System.out.print("that ");
        }
         System.out.println("it");
    } //end main method
 } //end class