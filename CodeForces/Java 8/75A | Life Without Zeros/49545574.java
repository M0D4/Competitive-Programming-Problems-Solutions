import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a=sc.next();
        String b=sc.next();
        long c=Long.valueOf(a)+Long.valueOf(b);
        String d=""+c;
        a=a.replace("0", "");
        b=b.replace("0", "");
        d=d.replace("0", "");
        if(Long.valueOf(a)+Long.valueOf(b)==Long.valueOf(d))
            System.out.println("YES");
        else System.out.println("NO");
    } //end main method
   } //end class