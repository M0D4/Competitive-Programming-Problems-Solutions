import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        String b="";
        int c=1;
        String d=sc.next();
        for (int i = 1; i < a; i++) {
                 b=sc.next();
               if(!b.equals(d)){
                   d=b;
                   c++;
           }
        }
                System.out.println(c);
    } //end main method
   } //end class