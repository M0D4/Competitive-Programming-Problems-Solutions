import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int a = Integer.valueOf("" + s.charAt(0));
        int b = Integer.valueOf("" + s.charAt(1));
        int c1 = 1;
        int c2 = 1;
         switch (a) {
            case 0:
                c1 += 1;
                break;
            case 1:
                c1 += 6;
                break;
            case 2:
                c1 += 1;
                break;
            case 3:
                c1 += 2;
                break;
            case 4:
                c1 += 2;
                break;
            case 5:
                c1 += 3;
                break;
            case 6:
                c1 += 1;
                break;
            case 7:
                c1 += 4;
                break;
            case 8:
                c1 += 0;
                break;
            case 9:
                c1 += 1;
                break;
        }
        switch (b) {
            case 0:
                c2 += 1;
                break;
            case 1:
                c2 += 6;
                break;
            case 2:
                c2 += 1;
                break;
            case 3:
                c2 += 2;
                break;
            case 4:
                c2 += 2;
                break;
            case 5:
                c2 += 3;
                break;
            case 6:
                c2 += 1;
                break;
            case 7:
                c2 += 4;
                break;
            case 8:
                c2 += 0;
                break;
            case 9:
                c2 += 1;
                break;
        }
        System.out.println(c1 * c2);
    } //end main method
 } //end class