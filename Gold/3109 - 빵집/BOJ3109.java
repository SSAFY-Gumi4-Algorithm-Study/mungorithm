import java.io.*;
import java.util.*;

public class BOJ3109 {
    static int n, m;
    static int[][] a;
    static boolean[][] visited;
    static int[] dy = { -1, 0, 1 };
    static int[] dx = { 1, 1, 1 };
    static int ret = 0;

    static boolean dfs(int y, int x) {
        visited[y][x] = true;
        if (x == m - 1) {
            ret++;
            return true;
        }

        for (int i = 0; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (!visited[ny][nx] && a[ny][nx] == 0) {
                if (dfs(ny, nx))
                    return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.')
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i][0] == 0)
                dfs(i, 0);
        }

        System.out.println(ret);
    }
}
