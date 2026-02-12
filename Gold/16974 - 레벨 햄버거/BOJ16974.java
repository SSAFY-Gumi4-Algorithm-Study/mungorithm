import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ16974 {
    static int n;
    static long x;
    static long[] dp1, dp2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Long.parseLong(st.nextToken());

        dp1 = new long[n + 1];
        dp2 = new long[n + 1];
        dp1[0] = 1;
        dp2[0] = 1;
        for(int i = 1; i <= n; i++){
            dp1[i] = dp1[i - 1] * 2 + 3;
            dp2[i] = dp2[i - 1] * 2 + 1;
        }
        System.out.println(solve(n, x));
    }

    static long solve(int level, long cnt){
        if(level == 0) return cnt >= 1 ? 1 : 0;
        else if(cnt == 1) return 0;
        else if(cnt == dp1[level - 1] + 1) return dp2[level - 1]; 
        else if(cnt < dp1[level - 1] + 1) return solve(level - 1, cnt - 1);
        else if(cnt == dp1[level - 1] + 2) return dp2[level - 1] + 1;
        else if(cnt <= dp1[level - 1] * 2 + 2) return dp2[level - 1] + 1 + solve(level - 1, cnt - dp1[level - 1] - 2);
        return dp2[level - 1] * 2 + 1;
    }
}
