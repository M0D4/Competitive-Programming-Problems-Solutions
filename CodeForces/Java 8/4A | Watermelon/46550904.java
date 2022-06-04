import java.util.Scanner;
//import java.math.BigInteger;
public class Test1 {
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
        //if the number is Primary and odd print NO else print YES
        int a=sc.nextInt();
        if (a==1){
                System.out.println("NO");
        }else{
        for(int i=2; i<=a;i++){ 
                        if(a%i==0){
                if(i<a &&a%2==0){
                System.out.println("YES");
                break;
                                }else{
                    System.out.println("NO");
                    break;
                }
            }
                            }
        }
          }
       }
  