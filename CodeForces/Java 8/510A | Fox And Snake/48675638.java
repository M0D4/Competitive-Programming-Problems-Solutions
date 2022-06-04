import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
  int b=sc.nextInt();
  int c=2;
    StringBuilder s1=new StringBuilder("#");
  StringBuilder s2=new StringBuilder("#");
   for(int i=1,j=1;i<b;i++){
   s1.append("."); 
   s2.append("#");
  }
  String s3=s1.reverse().toString();
  s1.reverse();
   for(int i=1;i<=a;i++){
   if(i%2 !=0)System.out.println(s2);
   else{
    if(c%2==0)System.out.println(s3);
    else System.out.println(s1);
    c++;
   }
  }
      } //end main method
 } //end class