 import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        String a=sc.next();
        String b=""+a.toLowerCase().charAt(0);
        b +=a.toUpperCase().substring(1);
        if (a.length()==1){
            if (a.toLowerCase().equals(a))b=b.toUpperCase();
            else b=b.toLowerCase();
        }
        else if (a.toUpperCase().equals(a)) b=a.toLowerCase();
        else if(a.equals(b)){ 
            b=""+a.toUpperCase().charAt(0);
            b+=a.toLowerCase().substring(1);
        }
        else b=a;
        System.out.println(b);
                                 } //end main method
 } //end class