import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int x=0;
        for (int i = 0; i < a; i++) {
            String b=sc.next();
            if(b.equals("++X")||b.equals("X++"))x++;
            else if(b.equals("--X")||b.equals("X--"))x--;
        }
        System.out.println(x);
    } //end main method
   } //end class