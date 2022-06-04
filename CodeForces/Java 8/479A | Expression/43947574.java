import java.util.Scanner;
  public class JavaApplication3 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       int a, b, c, x, y, z, m ,n;
     a= sc.nextInt();
     b=sc.nextInt();
     c= sc.nextInt();
             x= a*(b+c);
         y= a*b*c;
         z= a + (b*c);
         m= (a+b)*c;
         n= a+b+c;
         if (x>y && x>z && x>m && x>n){
             System.out.println(x);
        }else if (y>x && y>z && y>m && y>n){
             System.out.println(y);
        }else if (z>y && z>x && z>m && z>n){
             System.out.println(z);
        }else if (m>y && m>z && m>x && m>n){
             System.out.println(m);
        }else if (n>y && n>z && n>x && n>m){
             System.out.println(n);
        }else if (x==y |x==z |x==m |x==n){
             System.out.println(x);
        }
          }
}
 