import java.io.*;
import java.util.*;

public class BOJ7682 {
    static String s;
    static char[][] a;
    static StringBuilder ret = new StringBuilder();
    static int o, x;

    static boolean check() {
        if (x - o > 1)
            return false;
        else if (o - x > 0)
            return false;

        boolean xWin = false;
        boolean oWin = false;

        for (int i = 0; i < 3; i++) {
            if (a[i][0] != '.' && a[i][0] == a[i][1] && a[i][0] == a[i][2]) {
                if (a[i][0] == 'X')
                    xWin = true;
                else
                    oWin = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (a[0][i] != '.' && a[0][i] == a[1][i] && a[0][i] == a[2][i]) {
                if (a[0][i] == 'X')
                    xWin = true;
                else
                    oWin = true;
            }
        }

        if (a[0][0] != '.' && a[0][0] == a[1][1] && a[0][0] == a[2][2]) {
            if (a[0][0] == 'X')
                xWin = true;
            else
                oWin = true;
        }

        if (a[0][2] != '.' && a[0][2] == a[1][1] && a[0][2] == a[2][0]) {
            if (a[0][2] == 'X')
                xWin = true;
            else
                oWin = true;
        }

        if (xWin && oWin)
            return false;

        if (xWin) {
            return x == o + 1;
        }
        if (oWin) {
            return x == o;
        }
        return x + o == 9;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print(ret);
        while (true) {
            s = br.readLine();
            if (s.equals("end"))
                break;
            a = new char[3][3];
            int idx = 0;
            x = 0;
            o = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = s.charAt(idx++);
                    if (a[i][j] == 'O')
                        o++;
                    else if (a[i][j] == 'X')
                        x++;
                }
            }
            if (check())
                ret.append("valid\n");
            else
                ret.append("invalid\n");
        }
        System.out.print(ret);
    }
}
