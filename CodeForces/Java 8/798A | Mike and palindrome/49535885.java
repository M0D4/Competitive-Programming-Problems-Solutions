import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        StringBuilder a=new StringBuilder(s);
        StringBuilder b=new StringBuilder(s);
        boolean flag=true;
        int c=0;
        b.reverse();
        if(a.toString().equals(b.toString())){
            if(a.length()%2==0)
            flag =false;
        }
        else{
        for (int i = 0; i < a.length(); i++) {
           if(a.charAt(i)!=b.charAt(i)) c++;
            if(c>2){
                flag=false;
                break;
            }
        }
        }
        if(flag)System.out.println("YES");
        else System.out.println("NO");
    } //end main method
   } //end class