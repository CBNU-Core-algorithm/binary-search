import sys
input = sys.stdin.readline

# 속도 테스트
# list 는 시간초과 -> set을 쓰면?
# list와 set 사이에 in함수를 사용할 때의 시간복잡도 차이가 큰가?
# https://blog.naver.com/jin970510/222874610032

# 리스트에서의 x in s 연산의 평균 시간 복잡도 : O(n)
# 세트에서의 x in s 연산의 평균 시간 복잡도 : O(1)

# 백준 질문답변!
# https://www.acmicpc.net/board/view/76174

sort_num = int(input())
# sort_data = sorted(list(map(int, input().split(' '))))
nosort_data = set(map(int, input().split(' '))) # 순서나 인덱스에 따른 접근이 필요없다면, set이 시간복잡도면에서 좋다.
check_num = int(input())
check_data = list(map(int, input().split(' ')))

for x in check_data:


    if (x in nosort_data):
        answer = 1
    else:
        answer = 0

    print(answer, end=' ')

