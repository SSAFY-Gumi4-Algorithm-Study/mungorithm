import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ6549 {
    static int n;
    static int[] tree;
    static int[] a;
    static int len;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while (true) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            if (n == 0)
                break;
            len = 1;
            while (len < n)
                len <<= 1;
            tree = new int[len * 2];
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
                tree[i + len] = i;
            }
            for (int i = len - 1; i > 0; i--) {
                if (a[tree[i * 2]] < a[tree[i * 2 + 1]]) {
                    tree[i] = tree[i * 2];
                } else
                    tree[i] = tree[i * 2 + 1];
            }
            System.out.println(findSquare(0, n - 1));
        }
    }

    private static long findSquare(int s, int e) {
        int idx = findIdx(1, 0, len - 1, s, e);
        long ret = (long) (e - s + 1) * a[idx];

        if (s < idx) {
            ret = Math.max(ret, findSquare(s, idx - 1));
        }
        if (e > idx) {
            ret = Math.max(ret, findSquare(idx + 1, e));
        }
        return ret;
    }

    private static int findIdx(int idx, int s, int e, int ts, int te) {
        if (s > te || e < ts)
            return -1;
        else if (s >= ts && e <= te)
            return tree[idx];
        int mid = (s + e) / 2;
        int l = findIdx(idx * 2, s, mid, ts, te);
        int r = findIdx(idx * 2 + 1, mid + 1, e, ts, te);

        if (l == -1)
            return r;
        if (r == -1)
            return l;

        if (a[l] > a[r])
            return r;
        else
            return l;
    }
}
