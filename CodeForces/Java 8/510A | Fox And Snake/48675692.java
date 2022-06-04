import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c1 = 2;
        int c2 = 4;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (i % 2 != 0) {
                    System.out.print("#");
                } else if (i % 2 == 0) {
                    if (c1 < c2) {
                        if (j != b) {
                            System.out.print(".");
                        } else if (j == b) {
                            System.out.print("#");
                            c1 = c2 + 1;
                        }
                    } else {
                        if (j == 1) {
                            System.out.print("#");
                        } else {
                            System.out.print(".");
                            if (j == b) {
                                c2 = c1 + 1;
                            }
                        }
                    }
                 }
             }
            System.out.println();
        }
     } //end main method
 } //end class