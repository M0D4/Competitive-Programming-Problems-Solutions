import java.util.Scanner;
 public class Test2 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int c = 2, code = 99;
        int counter = 97;
        String pass = "ab";
        for (int i = 2; i < n; i++) {
            if (c < k) {
                pass += (char) code;
                c++;
                code++;
            } else {
                pass += (char) counter;
                if (++counter == code) {
                    counter = 97;
                }
            }
        }
        System.out.println(pass);
    }//end main method
 }//end class
 