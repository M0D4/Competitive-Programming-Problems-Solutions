import java.util.Scanner;
 public class Test2 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int n=sc.nextInt();
        String small="~";
        boolean flag=false;
        for (int i = 0; i <n; i++) {
           String a=sc.next();
            if(a.startsWith(s)){
                flag=true;
                if(a.compareTo(small)<0)small=a;
            }
        }
        if(flag)System.out.println(small);
        else System.out.println(s);
    }//end main method
 }//end class
 