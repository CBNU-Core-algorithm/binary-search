import sys

def make_sum_list(pizza_list):
    # 피자 원형 만들기
    lists = pizza_list + pizza_list

    # 구간합 리스트 만들기 ( 일반 리스트 값 접근형태로 만들면 안 되고, 인덱스(키/밸류) 접근 형태로 만들어야 시간 초과 안 난다) ( or 딕셔너리 )
    # 마지막 경우의수 더할 때는 순회의 시간복잡도 O(n) 을 쓰면 안되고, 인덱스 접근 O(1)을 쓸 수 있게 해야한다.
    sum_list = []
    n = len(pizza_list)

    # 인덱스 접근을 위한 0으로 채워진 리스트 만들기
    for x in range(2_000_000):
        sum_list.append(0)

    sum_list[0] = 1 # 0은 아무것도 선택하지 않았을 경우의 값

    for i in range(len(pizza_list)):
        for j in range(1, len(pizza_list)):
            sum_list[sum(lists[i:i+j])] += 1

    sum_list[sum(pizza_list)] += 1 # 전부 다 더 했을때의 값

    return sum_list

sys.stdin = open('a.txt', 'rt') # test입력용 코드

# 값 입력 받기
target = int(sys.stdin.readline())
m, n = list(map(int, sys.stdin.readline().split()))
list1 = []
list2 = []
for i in range(m):
    list1.append(int(sys.stdin.readline()))
for i in range(n):
    list2.append(int(sys.stdin.readline()))

# 원형 구간합 리스트 만들기
a = make_sum_list(list1)
b = make_sum_list(list2)
cnt = 0

# # 리스트 값 접근 순차 탐색 (시간 초과)
# for i in a:
#     for j in b:
#         if i + j == target:
#             cnt += 1

# 인덱스를 통한 탐색
a_len = len(a)
b_len = len(b)

result = 0
for i in range(a_len):
    if target - i >= 0:
        result += a[i] * b[target - i]

print(result)
'''
[0, 2, 4, 5, 12, 2, 3, 10, 12, 1, 8, 10, 12, 7, 9, 11, 13, 2, 4, 6, 7, 14]
[0, 6, 14, 8, 11, 3, 9, 17]
5
'''
