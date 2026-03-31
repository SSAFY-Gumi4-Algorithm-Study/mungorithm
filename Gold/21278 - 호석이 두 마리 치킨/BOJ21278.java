import java.io.*;
import java.util.*;

public class BOJ21278 {
    static int n, m;
    static int[][] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    a[i][j] = 0;
                else
                    a[i][j] = 987654321;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            a[from][to] = 1;
            a[to][from] = 1;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }

        int ret = 987654321;
        int x = -1;
        int y = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = 0;
                for (int k = 1; k <= n; k++) {
                    sum += Math.min(a[i][k], a[j][k]);
                }
                if (ret > sum) {
                    ret = sum;
                    x = i;
                    y = j;
                } else if (ret == sum) {
                    if (x > i) {
                        x = i;
                        y = j;
                    } else if (x == i && y > j) {
                        y = j;
                    }
                }
            }
        }

        System.out.print(x + " " + y + " " + ret * 2);
    }
}
