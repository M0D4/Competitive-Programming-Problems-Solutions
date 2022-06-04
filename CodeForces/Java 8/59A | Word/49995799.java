import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String a=sc.nextLine();
        String b=a.toLowerCase();
        int lower=0;
        int upper=0;
        for (int i = 0; i < a.length(); i++) {
            if(a.charAt(i)==b.charAt(i)) lower++;
            else upper++;
        }
        if(lower>=upper)System.out.println(b);
        else System.out.println(a.toUpperCase());
    }//end main method
    }//end class