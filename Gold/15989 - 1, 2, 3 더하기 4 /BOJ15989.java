import java.io.*;
import java.util.*;

public class BOJ15989 {
    static int n;
    static int[] dp = new int[10001];

    public static void main(String[] args) throws IOException{
        dp[0] = 1;
        for(int i = 1; i <= 3; i++){
            for(int j = i; j <= 10000; j++){
                dp[j] += dp[j - i];
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            int m = Integer.parseInt(br.readLine());
            System.out.println(dp[m]);
        }
    }
}
