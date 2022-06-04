import java.util.Scanner;
 public class Test2 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char a=sc.next().charAt(0);
        String b=sc.next();
        String c="qwertyuiopasdfghjkl;zxcvbnm,./";
        String corr="";
        if(a=='R')
        for (int i = 0; i < b.length(); i++) {
            corr+=c.charAt(c.indexOf(b.charAt(i))-1);
        }
        else if(a=='L')
            for (int i = 0; i < b.length(); i++) {
            corr+=c.charAt(c.indexOf(b.charAt(i))+1);
        }
        System.out.println(corr);
    }//end main method
 }//end class