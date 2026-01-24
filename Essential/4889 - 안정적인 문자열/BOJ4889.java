import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ4889 {
    static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 무한루프를 돌게 반복문
        for (int t = 1;; t++) {
            s = br.readLine(); // 입력 받기
            if (s.charAt(0) == '-') // -를 입력받는다면 루프 빠져나가기
                break;
            Stack<Character> stk = new Stack<>(); // 올바른 문자열인지 체크하기 위한 Stack 선언
            int ret = 0;

            // s문자열을 돌면서 체크
            for (int i = 0; i < s.length(); i++) {
                // '}' 일때
                if (s.charAt(i) == '}') {
                    // 스택이 비어있을때 }가 들어오는것은 올바른 문자열이 아니다
                    // { 을 push하도록 바꾸고 ret++
                    if (stk.empty()) {
                        stk.push('{');
                        ret++;
                    } 
                    // 가장 위의 문자가 { 라면 pop해줌 -> 올바른 문자열
                    else if (stk.peek() == '{') {
                        stk.pop();
                    }
                }
                // '{' 일때는 무조건 push!
                else {
                    stk.push('{');
                }
            }
            ret += stk.size() / 2; // 최종적으로 남은 { 들의 절반 만큼 }로 바꿔주면 올바른 문자열이 된다
            System.out.println(t + ". " + ret);
        }

    }
}
