import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
        //if the number is odd or 2 print NO else print YES
        int a=sc.nextInt();
        if (a%2!=0||a==2){
            System.out.println("NO");
        }else{
            System.out.println("YES");
        }
      }
       }