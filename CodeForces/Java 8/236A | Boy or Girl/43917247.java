import java.util.Scanner;
 public class JavaApplication3 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        a = a.toLowerCase();
       int sum = a.length();
        for (int i = 0; i<a.length(); i++) {
            for (int x=i+1 ; x<a.length() ; x++) {
                if (a.charAt(x)== a.charAt(i) ) {
                                sum--;
                break;
                }
            }
        }
         if (sum%2 ==0){
        System.out.println("CHAT WITH HER!");
         }else{
             System.out.println("IGNORE HIM!");
         }
     }
}