import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
        int a=sc.nextInt(),b=sc.nextInt(); 
    int count =1;
        while (true) {
            a *=3; 
            b *=2; 
            if (a<=b){
            count++;
            }else{
            break;
            }
        }
        System.out.println(count); 
    }
       }
 