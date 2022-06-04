import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = Math.max(a, b);
        a = 6 - c + 1;
        b = 6;
        int min = Math.min(a, b);
        for (int i = min; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                break;
            }
         }
        System.out.println(a + "/" + b);
    } //end main method
 } //end class