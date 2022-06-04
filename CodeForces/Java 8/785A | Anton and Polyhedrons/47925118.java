import java.util.Scanner;
 public class Test1 {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num=sc.nextInt();
        String shape;
        int faces=0;
        for (int i = 0; i < num; i++) {
            shape=sc.next();
            if (shape.equals("Tetrahedron")) faces+=4;
            else if (shape.equals("Cube")) faces+=6;
            else if(shape.equals("Octahedron")) faces+=8;
            else if(shape.equals("Dodecahedron")) faces+=12;
            else if(shape.equals("Icosahedron")) faces+=20;
        }
        System.out.println(faces);
    } //end main method
 } //end class