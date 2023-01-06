import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class divisorExample {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); //진짜 약수의 갯수
        int[] a = new int[N];//배열에 약수를 넣을 것
        st = new StringTokenizer(br.readLine()); // 새롭게 선언해서 약수를 읽어냄
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken()); // 배열 추가
        }
        Arrays.sort(a); // 진짜 수를 알아내기위해 정렬 (약수 ---> 두 번째 약수와 마지막 전 약수를 곱하면 그 수가 나온다.(짝수 홀수 불문))

        System.out.println(a[0] * a[N-1]);
    }
}
