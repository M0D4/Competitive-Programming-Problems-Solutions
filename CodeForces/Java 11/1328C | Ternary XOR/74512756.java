//testing Mahdy
  import java.util.Scanner;
 public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
          for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            String k = sc.next();
            StringBuilder first = new StringBuilder("1");
            StringBuilder second = new StringBuilder("1");
            int flag = 0;
              for (int it = 1; it < n; ++it) {
                switch (k.charAt(it)) {
                    case '0':
                        first.append("0");
                        second.append('0');
                        break;
                    case '1':
                        if (flag != 0) {
                            first.append('0');
                            second.append('1');
                            break;
                        }
                         flag = 1;
                        first.append('1');
                        second.append('0');
                        break;
                    case '2':
                        switch (flag) {
                            case 0:
                                first.append('1');
                                second.append('1');
                                break;
                            case 1:
                                first.append('0');
                                second.append('2');
                                break;
                            case 2:
                                first.append('2');
                                second.append('0');
                                flag = 1;
                        }
                }
            }
            System.out.println(first);
            System.out.println(second);
        }
     }
}