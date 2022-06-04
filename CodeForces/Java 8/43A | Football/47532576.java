import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int t1=1;
        int t2=0;
        String b[]=new String[a];
        String d="";
        for (int i = 0; i < b.length; i++) {
             b[i]=sc.next();
        }
        for (int i = 1; i < b.length; i++) {
            if(b[0].equals(b[i])) t1++;
            else {
                t2++;
                d=b[i];
            }
        }
        if (t1>t2)System.out.println(b[0]);
        else System.out.println(d);
     } //end main method
 } //end class