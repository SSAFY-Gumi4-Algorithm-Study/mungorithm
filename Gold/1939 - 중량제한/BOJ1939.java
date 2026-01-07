import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1939 {
    static int n, m;
    static ArrayList<Node>[] graph; 
    static int dist[];

    static class Node{
        int to, w;
        Node(int to, int w){
            this.to = to;
            this.w = w;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n + 1];
        dist = new int[n + 1];

        for(int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Node(b, c));
            graph[b].add(new Node(a, c));
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        System.out.println(dijkstra(start, end));
    }

    static int dijkstra(int start, int end){
        Arrays.fill(dist, 0);
        dist[start] = Integer.MAX_VALUE;
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> b.w - a.w);
        pq.offer(new Node(start, dist[start]));

        while(!pq.isEmpty()){
            Node cur = pq.poll();

            if(cur.w < dist[cur.to]) continue;
            if(cur.to == end) break;

            for(Node next : graph[cur.to]){
                int weight = Math.min(cur.w, next.w);

                if(dist[next.to] < weight){
                    dist[next.to] = weight;
                    pq.offer(new Node(next.to, weight));
                }
            }
        }
        return dist[end];
    }
}
