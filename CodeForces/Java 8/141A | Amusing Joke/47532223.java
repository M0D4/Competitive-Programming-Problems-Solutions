import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        String c=sc.next();
        int max=Math.max(a.length(), b.length());
        boolean flag = true;
        int d[] = new int[127];
        for (int i = 0; i < max; i++) {
           if(i<a.length()) d[(int)a.charAt(i)]++;
            if(i<b.length()) d[(int)b.charAt(i)]++;
        }
        int f[]=new int [127];
        for (int i = 0; i < c.length(); i++) {
            f[(int)c.charAt(i)]++;
        }
        for (int i = 65; i < 91; i++) { //uppercase letters codes
            if (d[i] != f[i]) {
                flag = false;
                break;
            }
        }
        if (flag)System.out.println("YES");
        else System.out.println("NO");
     } //end main method
 } //end class