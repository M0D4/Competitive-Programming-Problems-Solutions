import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
           String a= sc.nextLine(); //{4, 2, 6}
     a=a.substring(1, a.length()-1); //4, 2, 6
// subString will be from 1 to length-2
   a=a.replaceAll(",","");// 4 2 6
   a=a.replaceAll(" ", "");//426
   int c=a.length();
           for (int j=0; j<a.length(); j++) {
            for (int i=j+1; i<a.length(); i++) {
            if (a.charAt(j)==a.charAt(i)){
            c--;
            break;
            }
        }
        }
        System.out.println(c);
      }
       }
  