import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        //solution with contains method
        StringBuilder a=new StringBuilder(sc.next());
        a.reverse();
        String b=sc.next();
        if (a.toString().equals(b))System.out.println("YES");
        else System.out.println("NO");
        } //end main method
 } //end class