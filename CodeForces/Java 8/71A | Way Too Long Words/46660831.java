import java.util.Scanner;
//import java.math.BigInteger;
 public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        String ar[]=new String [a];
        for (int i = 0; i < a; i++) {
            String b=sc.next();
            if (b.length()<=10){
                ar[i]=b;
            }
            else {
                ar[i]=(b.charAt(0))+String.valueOf((b.length()-2))+(b.charAt(b.length()-1));
            }
                    }
        for (int i = 0; i < ar.length; i++) {
            System.out.println( ar[i]);
                    }
                                                        }
                          }
     