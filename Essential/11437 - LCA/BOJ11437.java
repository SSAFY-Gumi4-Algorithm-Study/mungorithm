import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ11437 {
    static int n, m;
    static ArrayList<Integer>[] tree;
    static int[][] parent;
    static int[] depth;
    static int len, h;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++){
            tree[i] = new ArrayList<>();
        }
        len = 1;
        h = 0;
        while(len < n){
            len <<= 1;
            h++;
        }
        parent = new int[n + 1][h + 1];
        depth = new int[n + 1];
        Arrays.fill(depth, -1);

        StringTokenizer st;
        for(int i = 0; i < n - 1; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            tree[from].add(to);
            tree[to].add(from);
        }
        depth[1] = 0;
        dfs(1);
        connect();
        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            System.out.println(LCA(a, b));
        }
    }

    private static void dfs(int cur){
        for(int next : tree[cur]){
            if(depth[next] == -1){
                parent[next][0] = cur;
                depth[next] = depth[cur] + 1;
                dfs(next);
            }
        }
    }

    private static void connect(){
        for(int i = 1; i <= h; i++){
            for(int cur = 1; cur <= n; cur++){
                parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
            }
        }
    }

    private static int LCA(int a, int b){
        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }

        int diff = depth[a] - depth[b];

        for(int i = 0; i <= h; i++){
            if((diff & (1 << i)) != 0){
                a = parent[a][i];
            }
        }

        if(a != b){
            for(int i = h; i >= 0; i--){
                if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];
        }
        return a;
    }
}
