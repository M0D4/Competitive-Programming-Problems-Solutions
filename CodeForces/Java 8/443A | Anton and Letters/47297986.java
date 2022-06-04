import java.util.Scanner;
 public class Test1 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
                   String a= sc.nextLine(); //{4, 2, 6}
   a=a.substring(1, a.length()-1); //4, 2, 6
   a=a.replaceAll(",","");// 4 2 6
   a=a.replaceAll(" ", "");//426
   int c=0;
        int b[]=new int[127]; //maximum uni code
        char v[]=a.toCharArray();
        for (int i = 0; i < v.length;i++) {
             b[v[i]]++;
        }
        for (int i = 0; i < b.length; i++) {
            if (b[i]!=0) c++;
        }
        System.out.println(c);
}//end main method
  } //end class