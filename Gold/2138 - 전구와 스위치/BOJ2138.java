import java.util.*;
import java.io.*;

public class BOJ2138 {
    static int n;
    static char[] a, b;

    static int solve(char[] s, char[] g) {
        int cnt = 0;
        for (int i = 1; i < s.length; i++) {
            if (s[i - 1] != g[i - 1]) {
                s[i - 1] = s[i - 1] == '0' ? '1' : '0';
                s[i] = s[i] == '0' ? '1' : '0';
                if (i + 1 < s.length) {
                    s[i + 1] = s[i + 1] == '0' ? '1' : '0';
                }
                cnt++;
            }
        }
        for (int i = 0; i < s.length; i++) {
            if (s[i] != g[i])
                return 987654321;
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = br.readLine().toCharArray();
        b = br.readLine().toCharArray();

        int ret = 987654321;
        ret = Math.min(ret, solve(a.clone(), b));
        a[0] = a[0] == '0' ? '1' : '0';
        a[1] = a[1] == '0' ? '1' : '0';
        ret = Math.min(ret, solve(a.clone(), b) + 1);
        if (ret == 987654321)
            System.out.println(-1);
        else
            System.out.println(ret);
    }
}
