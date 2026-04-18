import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1937 {
    static int n;
    static int[][] a;
    static int[][] dp;
    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, 1, 0, -1 };
    static int ret = 0;

    static int dfs(int y, int x) {
        if (dp[y][x] != -1)
            return dp[y][x];
        dp[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (a[y][x] < a[ny][nx])
                dp[y][x] = Math.max(dp[y][x], dfs(ny, nx) + 1);
        }
        return dp[y][x];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        a = new int[n][n];
        dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1)
                    ret = Math.max(ret, dfs(i, j));
            }
        }

        System.out.println(ret);
    }
}
