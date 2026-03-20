import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ2461 {
    static class Node {
        int val, cIdx, sIdx;

        private Node(int val, int cIdx, int sIdx){
            this.val = val;
            this.cIdx = cIdx;
            this.sIdx = sIdx;
        }
    }

    static int n, m;
    static int[][] a;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new int[n][m];

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            return a.val - b.val;
        });

        int max = -1;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(a[i]);
            pq.add(new Node(a[i][0], i, 0));
            max = Math.max(max, a[i][0]);
        }

        int ret = 987654321;
        ret = Math.min(ret, max - pq.peek().val);

        while(true){
            Node cur = pq.poll();
            int c = cur.cIdx;
            int idx = cur.sIdx;
            if(idx + 1 >= m) break;
            pq.add(new Node(a[c][idx + 1], c, idx + 1));
            max = Math.max(max, a[c][idx + 1]);
            ret = Math.min(ret, max - pq.peek().val);
        }

        System.out.println(ret);
    }
}
