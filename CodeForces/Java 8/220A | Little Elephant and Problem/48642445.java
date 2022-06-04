import java.util.Arrays;
import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
        int size=sc.nextInt();
        double counter=0;
        int x=0;
        int swap=0;
        boolean flag=true;
        int a[]=new int [size];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        int b[]=new int[size];
        System.arraycopy(a, 0, b, 0, b.length);
        Arrays.sort(b);
        for (int i = 0; i < a.length; i++) {
           if(a[i]!=b[i]){
            counter++;
            if ((counter/2.0)>1){
                flag=false;
                break;
            }
        }
        }
        if(flag)System.out.println("YES");
            else System.out.println("NO");
    } //end main method
    } //end class