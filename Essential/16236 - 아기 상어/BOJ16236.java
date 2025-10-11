import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ16236 {
    static int n;
    static int[][] a;
    static Shark baby;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int cnt = 0;
    static int ret = 0;

    static class Shark{
        int y, x, size;
        Shark(int y, int x, int size){
            this.y = y;
            this.x = x;
            this.size = size;
        }
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n][n];
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
                // 값이 9일때 상어의 정보를 저장하고 값을 0으로 바꾼다
                if(a[i][j] == 9) {
                    baby = new Shark(i, j, 2);
                    a[i][j] = 0;
                }
            }
        }
        // 물고기 못먹으면 while문 빠져나오기
        while(true){
            if(!findFish(baby.y, baby.x)) break;
        }
        System.out.println(ret);
    }

    // 먹을 수 있는 물고기를 찾고 조건에 맞는 물고기가 있다면 먹는 로직 진행후 true 리턴
    // 먹을 수 있는 물고기를 찾지 못하면 false 리턴
    private static boolean findFish(int y, int x){
        Queue<Pair> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[n][n];
        q.offer(new Pair(y, x));
        visited[y][x] = true;
        int dist = 0; // 가까운 물고기의 위치를 저장하기 위한 변수(bfs의 깊이)
        ArrayList<Pair> tmp = new ArrayList<>(); // 먹을수 있는 같은 레벨의 물고기가 여러마리 일 수 있으므로 list에 저장
        while(!q.isEmpty()){
            int size = q.size(); // 같은 레벨의 q만 진행 할 수 있게 size 변수 저장
            dist++; // while문은 같은 레벨의 bfs만 진행하므로 dist는 즉 깊이가 된다
            
            //bfs 코드 진행
            //size만큼 반복하므로 같은 레벨만큼의 bfs만 진행하게 된다.
            for(int i = 0; i < size; i++){
                Pair cur = q.poll();
                int sy = cur.y;
                int sx = cur.x;
                for(int d = 0; d < 4; d++){
                    int ny = sy + dy[d];
                    int nx = sx + dx[d];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if(visited[ny][nx]) continue;
                    if(baby.size < a[ny][nx]) continue; // 아기상어보다 큰 물고기가 있는 곳은 통과 불가능
                    q.offer(new Pair(ny, nx));
                    visited[ny][nx] = true;
                    // a[ny][nx]의 값이 0이 아니면서 아기상어 크기보다 작으면 tmp 리스트에 저장
                    if(a[ny][nx] != 0 && a[ny][nx] < baby.size){
                        tmp.add(new Pair(ny, nx));
                    }
                }
            }

            // 한 레벨의 bfs를 모두 진행을 했을때 tmp에 무언가가 저장이 되어있으면
            // 잡아먹을 물고기가 있는것이므로 bfs 탈출
            if(tmp.size() != 0){
                break;
            }
        }

        // 탈출 했을 때 tmp에 아무것도 저장이되어있지 않다면 (while 조건식으로 인해 탈출 한 경우) false 리턴
        if(tmp.size() == 0){
            return false;
        }

        // 물고기들 중 가장 위쪽, y위치가 같다면 가장 왼쪽 물고기를 먹기 때문에 조건에 맞게 정렬
        tmp.sort((a, b) -> {
            if(a.y == b.y) return a.x - b.x;
            return a.y - b.y;
        });

        Pair fish = tmp.get(0); // 잡아먹을 물고기 저장

        // 잡아 먹은 후 로직들
        a[fish.y][fish.x] = 0;
        baby.y = fish.y;
        baby.x = fish.x;

        cnt++; // 잡아먹은 개수 세기

        // 만약 아기상어 크기만큼 잡아먹으면 크기 1증가, cnt 초기화
        if(cnt == baby.size){
            baby.size++;
            cnt = 0;
        }

        ret += dist; // 이동 거리 = 걸린 시간
        return true;
    }
}
