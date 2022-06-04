import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int c=0;
        String a="";
        String temp="";
        for (int i = 0; i < n; i++) {
            int b=sc.nextInt();
            temp=""+b;
            a=""+b;
            a=a.replace("4","");
            a=a.replace("7","");
            if(temp.length()-a.length()<=k)c++;
        }
        System.out.println(c);
    }//end main method
    }//end class