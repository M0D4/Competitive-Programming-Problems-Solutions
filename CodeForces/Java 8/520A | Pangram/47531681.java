import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        String b = sc.next();
        b=b.toLowerCase();
        boolean flag = true;
        int c[] = new int[127];
        for (int i = 0; i < a; i++) {
            c[(int)b.charAt(i)]++;
        }
        for (int i = 97; i < 123; i++) {
            if (c[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag)System.out.println("YES");
        else System.out.println("NO");
     } //end main method
 } //end class