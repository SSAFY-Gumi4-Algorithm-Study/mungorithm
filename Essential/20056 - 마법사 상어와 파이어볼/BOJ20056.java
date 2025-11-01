import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ20056 {
    static int n, m, k;
    static int[] dy ={-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dx ={0, 1, 1, 1, 0, -1, -1, -1};

    // fireball의 위치를 저장할 클래스 생성
    static class Fireball{
        int y, x, m, d, s;
        Fireball(int y, int x, int m, int d, int s){
            this.y = y;
            this.x = x;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        ArrayList<Fireball> fireball = new ArrayList<>();
        for(int i = 0; i < m; i++){
            int y, x, m, d, s;
            st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            fireball.add(new Fireball(y, x, m, d, s)); // 각 파이어볼 정보 저장
        }

        while(k-- > 0){
            ArrayList<Integer>[][] map = new ArrayList[n + 1][n + 1]; // 이동후 파이어볼의 위치에 그 파이어볼 인덱스 저장
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    map[i][j] = new ArrayList<>();
                }
            }
            // fireball의 사이즈만큼 for 루프 돌리기
            for(int i = 0; i < fireball.size(); i++){
                Fireball cur = fireball.get(i);
                if(cur.m == 0) continue; // m이 0인것은 건너 뛴다. (m을 0으로 만들어주면서 삭제처리)
                int move = cur.s % n; 
                int ny = ((cur.y - 1 + dy[cur.d] * move) % n + n) % n + 1;
                int nx = ((cur.x - 1 + dx[cur.d] * move) % n + n) % n + 1;
                cur.y = ny;
                cur.x = nx;
                map[ny][nx].add(i); // 이동 완료후 map에 현재 파이어 볼의 인덱스 저장
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(map[i][j].size() < 2) continue; // 2개이상이라면 분해해야함
                    int sum_m = 0;
                    int sum_s = 0;
                    boolean isOdd = false;
                    boolean isEven = false;

                    // 파이어 볼들의 질량합, 속력합, 방향 판별을 해준다
                    for(int idx : map[i][j]){
                        Fireball tmp = fireball.get(idx);
                        sum_m += tmp.m;
                        sum_s += tmp.s;
                        if(tmp.d % 2 == 1) isOdd = true;
                        else isEven = true;
                        fireball.get(idx).m = 0; // 분해하고 난 후 fireball의 질량을 0으로 만들면서 삭제처리
                    }

                    int dir = (isOdd && isEven) ? 1 : 0; // 홀수, 짝수가 모두 나오면 idx 1부터시작 아니면 0
                    sum_m /= 5;
                    if(sum_m == 0) continue; // 질량이 0이되는것은 추가 저장 해줄 필요 없음
                    sum_s /= map[i][j].size();
                    for(int l = 0; l < 4; l++){
                        fireball.add(new Fireball(i, j, sum_m, dir, sum_s));
                        dir += 2;
                    }
                }
            }
        }
        int ret = 0;
        // 파이어볼의 질량 합 구하기
        for(Fireball fb : fireball){
            ret += fb.m;
        }
        System.out.println(ret);
    }
}
