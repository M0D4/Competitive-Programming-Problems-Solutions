import java.util.Scanner;
  public class JavaApplication3 {
             public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
     String a=sc.next();
     a=a.toLowerCase();
     String b=sc.next();
     b=b.toLowerCase();
     int c=0;
     int x = a.compareTo(b);
     if (x<0){
        System.out.println("-1");
     }else if (x>0){
         System.out.println("1");
     }else{
         System.out.println("0");
     }
    } //public static void
   } //Main Class End