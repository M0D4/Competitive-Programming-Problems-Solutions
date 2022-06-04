import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        //solution with contains method
        String a=sc.next();
        if (a.contains("0000000")||a.contains("1111111"))
            System.out.println("YES");
        else System.out.println("NO");
} //end main method
 } //end class