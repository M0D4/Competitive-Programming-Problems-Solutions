import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int a = Integer.valueOf("" + s.charAt(0));
        int b = Integer.valueOf("" + s.charAt(1));
        int c1 = 1;
        int c2 = 1;
        if (a==0 || a==2 || a==6 || a==9) c1 +=1;
        else if(a==1) c1 +=6;
        else if(a==3 || a==4) c1 +=2;
        else if(a==5) c1 +=3;
        else if(a==7) c1 +=4;
                if (b==0 || b==2 || b==6 || b==9) c2 +=1;
        else if(b==1) c2 +=6;
        else if(b==3 || b==4) c2 +=2;
        else if(b==5) c2 +=3;
        else if(b==7) c2 +=4;
                System.out.println(c1 * c2);
    } //end main method
 } //end class