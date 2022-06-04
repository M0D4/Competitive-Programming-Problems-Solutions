import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        String s=sc.next();
        StringBuilder sb=new StringBuilder(s);
        for (int i = 0; i < sb.length()-1; i++) {
            if(sb.charAt(i)==sb.charAt(i+1)){
                sb.deleteCharAt(i+1);
                i--;
            }
        }
        System.out.println(s.length()-sb.length());
    } //end main method
   } //end class