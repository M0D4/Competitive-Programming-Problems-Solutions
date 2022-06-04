import java.util.Scanner;
  public class JavaApplication3 {
     public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
    int a=sc.nextInt(),b=sc.nextInt(); 
    int count =1;
        for (int i=0; i<Math.pow(2, 16);i++) {
            a *=3; 
            b *=2; 
            if (a<b ||a==b){
            count++;
            }else{
            break;
            }
        }
        System.out.println(count);
    } //public static void
   } //Main Class End
 