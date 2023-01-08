import sys
# sys.stdin = open('a.txt', 'rt') # test용 코드
input = sys.stdin.readline

# 값 입력받기
n = int(input())
n_list = set(map(int, input().strip().split())) # set을 이용해서 in 시간복잡도 O(1)으로 줄이기
m = int(input())
m_list = list(map(int, input().strip().split()))

print('\n'.join(map(lambda x : '1' if x in n_list else '0', m_list)))
