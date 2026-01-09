import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class BOJ32358 {
    static int n;
    static TreeSet<Integer> set = new TreeSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        int cur = 0;
        long ret = 0;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            
            if(cmd == 1){
                int x = Integer.parseInt(st.nextToken());
                set.add(x);
            }
            else {
                while (!set.isEmpty()) {
                    Integer l = set.floor(cur);
                    Integer r = set.higher(cur);
                
                    int next;
                    if (l == null) {
                        next = r;
                    } else if (r == null) {
                        next = l;
                    } else {
                        int dl = cur - l;
                        int dr = r - cur;
                        if (dl <= dr) next = l;
                        else next = r;
                    }
                
                    ret += Math.abs(cur - next);
                    cur = next;
                    set.remove(next);
                }
            }
        }
        System.out.println(ret);
    }
}
