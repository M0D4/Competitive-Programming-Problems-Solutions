import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a1=sc.nextInt();
        int a2=sc.nextInt();
        int a3=sc.nextInt();
        int a4=sc.nextInt();
        int cal=0;
        String b=sc.next();
        for (int i = 0; i < b.length(); i++) {
            switch(b.charAt(i)){
                case '1':
                    cal +=a1;
                    break;
                case '2':
                    cal +=a2;
                    break;
                case '3':
                    cal +=a3;
                    break;
                case '4':
                    cal +=a4;
                    break;
            }
        }
        System.out.println(cal);
    } //end main method
   } //end class