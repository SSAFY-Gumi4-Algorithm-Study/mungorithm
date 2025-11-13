import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1781 {
    static int n;
    static ArrayList<Node> a = new ArrayList<>(); // 컵라면 정보를 저장할 객체 리스트 선언
    static PriorityQueue<Integer> pq = new PriorityQueue<>(); // pq를 사용해서 최적의 컵라면 저장

    // 데드라인과 개수를 저장하는 노드 클래스 선언
    static class Node{
        int day, cup;
        Node(int day, int cup){
            this.day = day;
            this.cup = cup;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            a.add(new Node(x, y));
        } // 입력 끝

        a.sort((r1, r2) -> {
            return r1.day - r2.day;
        }); // 데드라인을 기준으로 오름차순 정렬

        for(int i = 0; i < n; i++){
            pq.add(a.get(i).cup); // pq에 넣는다

            // 만약 pq사이즈가 day보다 크다면 정답이 될수없는 후보들을 뺀다
            // 이때 pq가 최소힙이기 때문에 가장 작은 친구들을 제거
            if(pq.size() > a.get(i).day){
                pq.poll();
            }
        }
        long ret = 0;
        while(!pq.isEmpty()) ret += pq.poll(); // pq에 빼면서 모두 더해주기
        System.out.println(ret);
    }
}
