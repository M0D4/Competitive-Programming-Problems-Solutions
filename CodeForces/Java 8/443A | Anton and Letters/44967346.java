import java.util.Scanner;
  public class JavaApplication3 {
     public static void main(String[] args) {
          Scanner sc = new Scanner( System.in );
        String a= sc.nextLine(); 
   a=a.substring(1, a.length()-1); 
   a=a.replaceAll(",","");
    int c=a.length();
           for (int j=0; j<a.length(); j++) {
            for (int i=j+1; i<a.length(); i++) {
            if (a.charAt(j)==a.charAt(i) && a.charAt(i)!=' '){
            c--;
            break;
            }
        }
            if (a.charAt(j)==' '){
        c--;
        }
        }
        System.out.println(c);
      } //public static void
       } //Main Class End
 