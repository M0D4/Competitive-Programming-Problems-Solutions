import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String a=sc.next();
        String b=sc.next();
        int pos=1;
        for (int i = 0,j=0; j < b.length(); j++) {
            if(b.charAt(j)==a.charAt(i)){
                i++;
                pos++;
            }
        }
        System.out.println(pos);
    }//end main method
    }//end class