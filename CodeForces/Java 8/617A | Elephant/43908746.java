import java.util.Scanner;
 public class JavaApplication3 {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
       int x = sc.nextInt();
      if (x%5==0){
          System.out.println(x/5);
      }else{
                System.out.println(x/5 +1);
      }
            }
}
   