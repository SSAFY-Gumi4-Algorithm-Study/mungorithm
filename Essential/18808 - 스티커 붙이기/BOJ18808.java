import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ18808 {
    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    static int n, m, k;
    static int[][] a;
    static Pair[] sz;
    static ArrayList<ArrayList<Integer>>[] sticker;
    static int ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        sticker = new ArrayList[k];
        sz = new Pair[k];
        a = new int[n][m];

        for(int i = 0; i < k; i++){
            sticker[i] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            sz[i] = new Pair(r, c);
            
            for(int j = 0; j < r; j++){
                st = new StringTokenizer(br.readLine());
                ArrayList<Integer> row = new ArrayList<>();
                for(int k = 0; k < c; k++){
                    row.add(Integer.parseInt(st.nextToken()));
                }
                sticker[i].add(row);
            }
        }
        for(int i = 0; i < k; i++){
            attach(i);
        }

        System.out.println(ret);
    }

    private static void attach(int idx){
        int cnt = 0;
        while(cnt < 4){
            for(int i = 0; i <= n - sz[idx].y; i++){
                for(int j = 0; j <= m - sz[idx].x; j++){
                    boolean flag = false;
                    for(int k = 0; k < sz[idx].y; k++){
                        for(int l = 0; l < sz[idx].x; l++){
                            if(a[i + k][j + l] == 1 && sticker[idx].get(k).get(l) == 1){
                                flag = true;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(!flag){
                        check(idx, i, j);
                        return;
                    }
                }
            }
            rotate(idx);
            cnt++;
        }
    }

    private static void check(int idx, int y, int x){
        for(int i = y; i < y + sz[idx].y; i++){
            for(int j = x; j < x + sz[idx].x; j++){
                if(a[i][j] == 0 && sticker[idx].get(i - y).get(j - x) == 1){
                    a[i][j] = 1;
                    ret++;
                } 
            }
        }
    }

    private static void rotate(int idx){
        int r = sz[idx].y;
        int c = sz[idx].x;
        ArrayList<ArrayList<Integer>> tmp = new ArrayList<>();
        for(int i = 0; i < c; i++){
            tmp.add(new ArrayList<>(Collections.nCopies(r, 0)));
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                tmp.get(j).set(r - 1 - i, sticker[idx].get(i).get(j));
            }
        }

        sticker[idx] = tmp;
        sz[idx].y = c;
        sz[idx].x = r;
    }
}
