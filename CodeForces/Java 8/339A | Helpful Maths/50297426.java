import java.util.Scanner;
import java.util.Arrays;
 public class Test1{
 public static void main(String[] args){
  Scanner sc=new Scanner(System.in);
  String a=sc.next();
  String b[]=a.split("\\+");
  Arrays.sort(b);
  a="";
  for(int i=0;i<b.length-1;i++){
   a+=b[i]+"+";
  }
  a+=b[b.length-1]+"";
  System.out.println(a);
 }//end main method
}//end class