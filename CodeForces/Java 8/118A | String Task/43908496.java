import java.util.Scanner;
 public class JavaApplication3 {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
       String a = sc.nextLine();
       a = a.toLowerCase();
        for (int i=0 ; i < a.length() ;i++){
           if (a.charAt(i)=='a' | a.charAt(i)=='o' | a.charAt(i)=='u' | a.charAt(i)=='e' | a.charAt(i)=='y' | a.charAt(i)=='i')
           {
               System.out.print("");
           }else{
                          System.out.print("." + a.charAt(i));
           }
    }
           System.out.println("");
    }
    }