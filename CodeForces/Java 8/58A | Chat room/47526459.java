import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        String a=sc.next();
        if (a.matches("(.*)h(.*)e(.*)l(.*)l(.*)o(.*)"))
            System.out.println("YES");
        else System.out.println("NO");
 } //end main method
 } //end class