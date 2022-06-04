import java.util.Arrays;
import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt() ,j=0;
        int a[]=new int [n];
        int b[]=new int [n];
        long even=0 ,odd=0;
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
            if(a[i]%2==0) even +=a[i];
          else {
                odd +=a[i];
                b[j]=a[i];
                j++;
            }
        }
        int c[]=new int [j];
        c=Arrays.copyOf(b,j); 
        if(odd%2==0)System.out.println(even+odd);
        else{
        Arrays.sort(c);
        System.out.println(even +odd -c[0]);
        }
    } //end main method
 } //end class