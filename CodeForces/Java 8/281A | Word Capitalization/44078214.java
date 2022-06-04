import java.util.Scanner;
public class JavaApplication3 {
     public static void main(String[] args) {
  Scanner sc = new Scanner(System.in) ;
   String a = sc.next();
   String b;
       b= a.toUpperCase();
            System.out.print(b.charAt(0));
         for (int i =1; i<a.length(); i++) {
            System.out.print(a.charAt(i));
                    }
        System.out.println("");
    }
}
 