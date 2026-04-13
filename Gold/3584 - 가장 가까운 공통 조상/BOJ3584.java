import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BOJ3584 {
    static int T;
    static int n;
    static int a, b;
    static int[] parent;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            n = Integer.parseInt(br.readLine());
            parent = new int[n + 1];
            
            for(int i = 0; i < n - 1; i++){
                st = new StringTokenizer(br.readLine());
                int next = Integer.parseInt(st.nextToken());
                int cur = Integer.parseInt(st.nextToken());
                parent[cur] = next; 
            }

            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            int cur = a;
            HashSet<Integer> s = new HashSet<>();
            while(cur != 0){
                s.add(cur);
                cur = parent[cur];
            }

            cur = b;
            while(cur != 0){
                if(s.contains(cur)){
                    sb.append(cur).append('\n');
                    break;
                }
                cur = parent[cur];
            }
        }
        System.out.println(sb);
    }
}
