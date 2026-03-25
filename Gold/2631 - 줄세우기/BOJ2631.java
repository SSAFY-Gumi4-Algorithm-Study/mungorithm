import java.util.*;
import java.io.*;

public class BOJ2631 {
    static int n;
    static int[] a, dp;

    static int lowerBound(int[] arr, int size, int key) {
        int l = 0;
        int r = size - 1;
        int ret = size;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= key) {
                ret = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        a = new int[n];
        dp = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        int idx = 0;
        dp[0] = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] > dp[idx]) {
                dp[++idx] = a[i];
            } else {
                int pos = lowerBound(dp, idx, a[i]);
                dp[pos] = a[i];
            }
        }
        System.out.println(n - idx - 1);
    }
}
