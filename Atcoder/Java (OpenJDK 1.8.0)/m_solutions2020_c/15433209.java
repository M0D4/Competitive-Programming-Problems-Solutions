
import static java.lang.Math.*;
import java.util.Scanner;



public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt(), l = 0;
        long a[] = new long[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextInt();
        double lg1 = 0;
        for(int i = 0; i < k; i++) lg1 += log(a[i]);
        for(int i = k; i < n; i++){
            double lg2 = lg1 - log(a[l++]) + log(a[i]);
            if(lg2 > lg1)System.out.println("Yes");
            else System.out.println("No");
            lg2 = lg1;
        }
    }
}
