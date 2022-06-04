import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        boolean flag=true;
        while(true){
            a++;
            String b=a+"";
            flag=true;
            for (int i = 0; i < b.length(); i++) {
                if(b.indexOf(b.charAt(i))!=b.lastIndexOf(b.charAt(i))){
                    flag=false;
                    break;
                }
            }
            if(flag){
                System.out.println(b);
                break;
            }
                    }
            }//end main method
    }//end class