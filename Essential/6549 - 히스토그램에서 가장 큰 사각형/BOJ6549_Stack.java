import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ6549 {
    static int n;
    static int[] a;
    static long ret = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ret = 0;
            n = Integer.parseInt(st.nextToken());
            if (n == 0)
                break;
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            Stack<Integer> stk = new Stack<>();
            for (int i = 0; i <= n; i++) {
                int cur = (i == n) ? 0 : a[i];

                while (!stk.empty() && a[stk.peek()] > cur) {
                    int h = a[stk.pop()];

                    int w;
                    if (stk.isEmpty())
                        w = i;
                    else
                        w = i - stk.peek() - 1;

                    ret = Math.max(ret, (long) w * h);
                }
                stk.push(i);
            }

            System.out.println(ret);
        }
    }
}
