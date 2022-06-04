import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner sc=new Scanner(System.in);
  int a=sc.nextInt();
  int z=0, o=0;
  String b=sc.next();
  for(int i=0;i<a;i++)
    if(b.charAt(i)=='0') z++;
     else o++;
    System.out.println(Math.abs(z-o));
 }//end main method
}//end class