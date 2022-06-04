import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt() ,c=0;
        int a[]=new int[n];
        for (int i = 0; i <n; i++) {
            a[i]=sc.nextInt();
        }
        for (int i = 0; i < a.length; i++) {
            if(a[i]>=a[k-1] &&a[i]>0)c++;
        }
        System.out.println(c);
    } //end main method
   } //end class