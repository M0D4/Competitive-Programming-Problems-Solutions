import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         int a=sc.nextInt();
         int max=sc.nextInt();
         int min=max;
         int c=0;
         for (int i = 1; i <a; i++) {
           int b=sc.nextInt();
           if(b<min){
               min =b;
               c++;
           }if(b>max){
               max=b;
               c++;
           }
        }
         System.out.println(c);
    } //end main method
 } //end class