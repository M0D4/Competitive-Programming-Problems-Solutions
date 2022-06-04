import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a[][]=new int[5][5];
        int b=0,c=0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                a[j][i]=sc.nextInt();
                if(a[j][i]==1){
                    b=i;
                    c=j;
            }
            }
        }
        b=Math.abs(2-b);
        c=Math.abs(2-c);
        System.out.println(b+c);
    } //end main method
   } //end class