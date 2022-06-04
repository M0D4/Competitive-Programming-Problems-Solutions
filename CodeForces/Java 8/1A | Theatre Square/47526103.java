import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        //solution with casting 
        int n=sc.nextInt(),m=sc.nextInt() ,a=sc.nextInt() ;
        double x=(double)n/a;
        if((long)x-x<0) x++;
        double y=(double)m/a;
        if((long)y-y<0)y++;
        System.out.println((long)x*(long)y);
 } //end main method
 } //end class
  