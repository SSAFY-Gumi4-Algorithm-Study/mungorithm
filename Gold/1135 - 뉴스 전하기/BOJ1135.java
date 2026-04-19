import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ1135 {
    static int n;
    static ArrayList<Integer>[] tree;
    static int[] a;

    static int dfs(int cur){
        ArrayList<Integer> arr = new ArrayList<>();
        for(int next : tree[cur]){
            arr.add(dfs(next));
        }

        if(arr.size() == 0) return 0;

        arr.sort((a, b) -> {
            return b - a;
        });

        int ret = 0;
        for(int i = 0; i < arr.size(); i++){
            ret = Math.max(ret, arr.get(i) + i + 1);
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        tree = new ArrayList[n];
        a = new int[n];
        for(int i = 0; i < n; i++){
            tree[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
             int parent = Integer.parseInt(st.nextToken());
            if(i == 0) continue;
            tree[parent].add(i);
        }

        System.out.println(dfs(0));
    }
}
