import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a=sc.next();
        char b[]=a.toCharArray();
        char temp;
        for (int i = 0; i < b.length; i++) {
            for (int j = i+1; j < b.length; j++) {
        if (b[i]!='+'&& b[j]!='+' &&(int)b[i]>(int)b[j]){
                 temp=b[i];
                 b[i]=b[j];
                 b[j]=temp;
            }                
            }
        }
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i]);
        }
        System.out.println("");
    } //end main method
 } //end class