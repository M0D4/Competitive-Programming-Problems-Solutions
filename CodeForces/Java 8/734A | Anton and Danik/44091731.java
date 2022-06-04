import java.util.Scanner;
public class JavaApplication3 {
     public static void main(String[] args) {
  Scanner sc = new Scanner(System.in) ;
   int q = sc.nextInt();
   String x = sc.next();
   x  = x.substring(0, q);
   x = x.toUpperCase();
   int a = 0;
   int d = 0;
        for (int i =0; i<x.length();i++) {
            if (x.charAt(i)== 'A'){
            a++;
            }else if (x.charAt(i)=='D'){
            d++;
            }
        } if (a>d){
        System.out.println("Anton");
        }else if (d>a){
        System.out.println("Danik");
        }else{
        System.out.println("Friendship");
        }
           }
}