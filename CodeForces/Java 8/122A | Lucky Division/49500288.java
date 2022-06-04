import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        boolean flag1=true;
        boolean flag2=false;
        for (int i = a; i >=4; i--) {
            String b="";
            b+=i;
            for (int j = 0; j < b.length(); j++)
                if(b.charAt(j)!='4' && b.charAt(j)!='7'){
                flag1 =false;
                    break;
                }
                                if(flag1){
                    if(a%i==0){
                        flag2=true;
                        break;
                    }
                }
                flag1=true;
        }
        if(flag2)System.out.println("YES");
        else System.out.println("NO");
    } //end main method
   } //end class