import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ1939_re {
    static int n, m;
    static int s, e;
    static ArrayList<Edge> edge = new ArrayList<>(); 
    static int parent[];
    
    static class Edge{
        int a, b, cost;
        private Edge(int a, int b, int cost){
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
    }

    static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    static boolean merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[y] = x;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        parent = new int[n + 1];
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edge.add(new Edge(a, b, cost));
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        Collections.sort(edge, (a, b) -> {
            return b.cost - a.cost;
        });

        for(int i = 0; i < m; i++){
            Edge cur = edge.get(i);
            if(merge(cur.a, cur.b)){
                if(find(s) == find(e)){
                    System.out.println(cur.cost);
                    return;
                }
            }
        }
    }
}
