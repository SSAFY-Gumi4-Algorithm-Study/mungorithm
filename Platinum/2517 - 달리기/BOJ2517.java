import java.io.*;
import java.util.*;

public class BOJ2517 {
    static int n;
    static int[] tree;
    static StringBuilder ret = new StringBuilder();

    static void update(int idx) {
        while (idx <= n) {
            tree[idx] += 1;
            idx += (idx & -idx);
        }
    }

    static int sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        int[] comp = new int[n];
        for(int i = 0; i < n; i++){
            comp[i] = Arrays.binarySearch(sorted, arr[i]) + 1;
        }
        tree = new int[n + 1];
        
        for(int i = 0; i < n; i++){
            int rank = comp[i];

            int faster = i - sum(rank);
            ret.append(faster + 1).append('\n');
            update(rank);
        }

        System.out.print(ret);
    }
}
