import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt() ;double sum=0;
        for (int i = 0; i <a; i++) sum+=sc.nextInt();
        System.out.println(sum/a);
} //end main method
 } //end class