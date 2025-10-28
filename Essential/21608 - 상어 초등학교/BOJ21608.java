import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BOJ21608 {
    static int n;
    static ArrayList<Integer>[] a;
    static int[][] map;
    static int[] idx;
    static int[] dy = { -1, 0, 1, 0};
    static int[] dx = { 0, 1, 0, -1};
    static int ret = 0;

    // 좌석후보들을 저장할 클래스 생성
    static class Info{
        int y, x, like, blank;
        Info(int y, int x, int like, int blank){
            this.y = y;
            this.x = x;
            this.like = like;
            this.blank = blank;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new ArrayList[n * n + 1];
        map = new int[n + 1][n + 1];
        idx = new int[n * n + 1];
        for(int i = 1; i <= n * n; i++){
            a[i] = new ArrayList<>();
        }
        StringTokenizer st;
        for(int i = 0; i < n * n; i++){
            st = new StringTokenizer(br.readLine());
            idx[i] = Integer.parseInt(st.nextToken());
            for(int j = 0; j < 4; j++){
                a[idx[i]].add(Integer.parseInt(st.nextToken()));
            }
        }
        // 입력 끝

        // for루프를 돌면서 모든 학생의 자리를 findPosition 함수를 통해 앉을 좌석의 정보를 담은 객체 반환
        for(int i = 0; i < n * n; i++){
            Info info = findPosition(idx[i]);
            map[info.y][info.x] = idx[i];
        }


        // 좌석의 주변에 좋아하는 학생의 분포에 따라 점수 계산
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ret += calScore(i, j, map[i][j]);
            }
        }
        System.out.println(ret);
    }

    // 정해진 규칙에 따른 좌석 정보 반환
    private static Info findPosition(int num){
        HashSet<Integer> s = new HashSet<>();
        ArrayList<Info> infos = new ArrayList<>();
        // 좋아하는 학생의 번호들을 set에 저장
        for(int i : a[num]){
            s.add(i);
        }
        // 빈칸일때 좌석의 후보가 되고 주변을 탐색하여 조건을 계산한다(인접한 좋아하는 학생 수, 인접한 빈칸)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(map[i][j] != 0) continue;
                int like = 0;
                int blank = 0;
                for(int dir = 0; dir < 4; dir++){
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
                    if(map[ny][nx] == 0) blank++;
                    if(s.contains(map[ny][nx])) like++;
                }
                infos.add(new Info(i, j, like, blank)); // infos리스트에 저장
            }
        }
        // 문제에서 말하는 방식으로 정렬
        infos.sort((a, b) -> {
            if(a.like == b.like){
                if(a.blank == b.blank){
                    if(a.y == b.y){
                        return a.x - b.x;
                    }
                    return a.y - b.y;
                }
                return b.blank - a.blank;
            }
            return b.like - a.like;
        });

        return infos.get(0); // 가장 앞의 infos 반환(조건에 맞는 자리)
    }

    private static int calScore(int y, int x, int num){
        HashSet<Integer> s = new HashSet<>();
        // set에 num학생이 좋아하는 학생들 저장
        for(int i : a[num]){
            s.add(i);
        }
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
            if(s.contains(map[ny][nx])) cnt++; // 좋아하는 학생이 주변에 있으면 cnt++
        }
        if(cnt == 0) return 0;
        else if(cnt == 1) return 1;
        else if(cnt == 2) return 10;
        else if(cnt == 3) return 100;
        else return 1000;
    }
}
