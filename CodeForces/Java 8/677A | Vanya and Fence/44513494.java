import java.util.Scanner;
  public class JavaApplication3 {
     public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
    int x=sc.nextInt();
    int y=sc.nextInt();
    int width =0;
    int a []=new int [x];
        for (int i=0;i<a.length;i++) {
            a[i]=sc.nextInt();
             if (a[i]<=y){
        width++;
        }else{
             width +=2;
             }
        }
        System.out.println(width);
           } //public static void
   } //Main Class End