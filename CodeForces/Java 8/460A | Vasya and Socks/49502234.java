import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();//number of pairs
        int m=sc.nextInt();//days before buying again
        int pairs=n;
        int counter=0;
        while(pairs>0){
            counter++;
            pairs--;
            if(counter%m==0)pairs++;
        }
        System.out.println(counter);
    } //end main method
   } //end class