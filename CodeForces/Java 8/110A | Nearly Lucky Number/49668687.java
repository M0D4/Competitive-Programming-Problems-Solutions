import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a=sc.nextLong();
        String b=""+a;
        int c=0;
        for (int i = 0; i < b.length(); i++) {
           if(b.charAt(i)=='7'||b.charAt(i)=='4') c++;
        }
        boolean flag=true;
        String d=""+c;
        for (int i = 0; i < d.length(); i++) {
            if(d.charAt(i)!='4'&&d.charAt(i)!='7'){
                flag=false;
                break;
            }
        }
                if(flag)System.out.println("YES");
        else System.out.println("NO");
    } //end main method
   } //end class