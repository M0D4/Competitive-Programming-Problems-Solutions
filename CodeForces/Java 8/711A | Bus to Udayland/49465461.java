import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       int a=sc.nextInt();
       int c=0;
       String b[]=new String[a];
        for (int i = 0; i <a; i++) {
            b[i]=sc.next();
            if(c==0){
            if(b[i].startsWith("OO")){
                b[i]="++"+b[i].substring(2);
                c++;
            }else if(b[i].endsWith("OO")){
                b[i]=b[i].substring(0,b[i].length()-2)+"++";
                c++;
            }
            }
        }
        if(c==0)System.out.println("NO");
        else{
            System.out.println("YES");
            for (int i = 0; i < b.length; i++) {
                    System.out.println(b[i]);
            }
        }
    } //end main method
    } //end class