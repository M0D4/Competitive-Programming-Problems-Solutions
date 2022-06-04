import java.util.Scanner;
 public class Test2 {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c1=0 ,c2=0;
        int x=a, y=b;
        while(x!=0 && y!=0){
            c1++;
            x--;
            y--;
        }
        if(x>=2){
            c2 +=x/2;
        }
        if(y>=2){
            c2 +=y/2;
        }
        System.out.println(c1+" "+c2);
            }//end main method
    }//end class