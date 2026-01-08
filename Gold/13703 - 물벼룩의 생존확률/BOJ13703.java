import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ13703 {
    static int k, n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        if (k == 0) {
            System.out.println(0);
            return;
        }

        int mx = n + k + 2;
        long[] dp = new long[mx];
        dp[k] = 1;
        for(int i = 1; i <= n; i++){
            long[] ndp = new long[mx];
            for(int j = 1; j < mx; j++){
                if(dp[j] != 0){
                    if(j - 1 >= 1) ndp[j - 1] += dp[j];
                    ndp[j + 1] += dp[j];
                }
            }
            dp = ndp;
        }
        long ret = 0;
        for(int i = 1; i < mx; i++){
            ret += dp[i];
        }
        System.out.println(ret);
    }
}
