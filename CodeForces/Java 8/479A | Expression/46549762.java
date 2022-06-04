import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
                    int a, b, c,max;
     a= sc.nextInt();
     b=sc.nextInt();
     c= sc.nextInt();
         int []k=new int [5];
        k[0]= a*(b+c);
        k[1]= a*b*c;
        k[2]= a + (b*c);
        k[3]= (a+b)*c;
        k[4]= a+b+c;
                max=k[0]; 
         for (int i = 1; i < k.length; i++) {
            if (k[i]>max){
            max=k[i];
            }
        }
         System.out.println(max);        
    }
       }