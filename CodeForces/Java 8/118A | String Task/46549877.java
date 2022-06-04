import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
                  String a=sc.nextLine();
        a=a.toLowerCase();
        a=a.replaceAll("a","");
        a=a.replaceAll("o", "");
        a=a.replaceAll("u", "");
        a=a.replaceAll("e", "");
        a=a.replaceAll("y", "");
        a=a.replaceAll("i", "");
        for (int i = 0; i < a.length(); i++) {
            System.out.print("."+a.charAt(i));
        }
        System.out.println("");       
    }
       }