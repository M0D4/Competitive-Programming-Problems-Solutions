import java.util.Scanner;
 public class JavaApplication3 {
     public static void main(String[] args) {
                Scanner sc= new Scanner(System.in);
        int a [] = new int [4];
        a[0]= sc.nextInt();
        a[1]= sc.nextInt();
        a[2]= sc.nextInt();
        a[3]= sc.nextInt();
        int co = 0;
                   for (int i = 0; i<a.length; i++) {
                for (int j =i+1; j<a.length; j++) {
                if (a[i]==a[j]){
                co++;
                break;
                }
               }  
            }
             System.out.println(co);
     }
}
   