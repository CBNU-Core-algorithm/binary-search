import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;

public class JavaSearchNumber {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //Scanner와 같은 역할
        int N = Integer.parseInt(br.readLine()); //숫자 입력 (원래 입력을 받으면 String 형태로 반환이 되기 때문에 정수 형으로 형 변환을 해 준다.
        int[] a = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine()); //받은 문자 열을 띄어 쓰기나 delim 에서 정한 개행 문자로 나눈다
        StringBuilder sb = new StringBuilder(); //True / false 담을 배열..?

        for(int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken()); //개행문자 기준으로 토큰을 나누고 배열에 담음
        }

        Arrays.sort(a); //비교를 위해 오름 차순으로 정렬

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for(int j = 0; j < M; j++){
            int b = Integer.parseInt(st.nextToken()); // b에
            if(Arrays.binarySearch(a, b) >= 0) {
                sb.append(1).append("\n");
            }
            else{
                sb.append(0).append("\n");
            }
        }

        System.out.println(sb);
    }
}