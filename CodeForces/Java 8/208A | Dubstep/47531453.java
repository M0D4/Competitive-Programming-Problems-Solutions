import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        String a=sc.nextLine();
        a=a.replaceAll("WUB", " ");
        a=a.trim();
        System.out.println(a);
        } //end main method
 } //end class