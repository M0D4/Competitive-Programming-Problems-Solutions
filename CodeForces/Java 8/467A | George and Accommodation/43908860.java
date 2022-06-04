import java.util.Scanner;
 public class JavaApplication3 {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
                               int sum = 0 ;
            int x [] = new int [ sc.nextInt()];
            int y [] = new int [2];
        for (int i = 0; i<x.length ; i++){
            for (int a =0; a<y.length; a++){
                y[a] = sc.nextInt();
            }
            if (y[0] +1 < y[1]){
                sum = sum + 1 ;
        }
             }
        System.out.println(sum);
            }
}
   