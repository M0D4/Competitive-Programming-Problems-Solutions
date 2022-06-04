import java.util.Scanner;
//import java.math.BigInteger;
 public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
                       int n=sc.nextInt(),m=sc.nextInt(),a=sc.nextInt(),c; 
        long x=n/a;
        long y=m/a;
        if (n%a !=0)x++;
        if (m%a !=0)y++;
        System.out.println(x*y);
              }
 }