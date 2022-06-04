import java.util.Scanner;
public class JavaApplication3 {
     public static void main(String[] args) {
  Scanner sc = new Scanner(System.in) ;
     int a = sc.nextInt();
    int x []=new int [3];
    int b = 0;
        for (int i = 0; i<a; i++) {
            for (int j=0; j<x.length;j++) {
              x[j]=sc.nextInt();}
              if (x[0]==1 && x[1]==1 && x[2]==1){
              b++;
              }else if(x[0]==1 && x[1]==0 &&x[2]==1){
              b++;
              }else if(x[0]==1 && x[1]==1 &&x[2]==0){
              b++;
              }else if(x[0]==0 && x[1]==1 &&x[2]==1){
              b++;
                            }
            }
                System.out.println(b);
    }
             }
 