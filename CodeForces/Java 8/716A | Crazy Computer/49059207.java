import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
               int n=sc.nextInt();
               int c=sc.nextInt();
               int words=n;
               int sec[]=new int[n];
               for (int i = 0; i < sec.length; i++) sec[i]=sc.nextInt();
               for (int i = 0,j=1; j < sec.length; i++,j++) {
            if(Math.abs(sec[i]-sec[j])>c) words=n-j;
        }
               System.out.println(words);
    } //end main method
 } //end class