import sys

# 값 입력받고, 2차원 배열로 저장하기
data = []
n = int(sys.stdin.readline())
for i in range(n):
    data.append(list(map(int, input().split())))


# 이진탐색 하기 전 계산에 필요한 변수 정리
start = 0
end = 0 # 컴퓨터가 가장 많은 방의 컴퓨터의 수
sum = 0  # 총 컴퓨터의 개수
for i in range(n):
    for j in range(n):
        sum += data[i][j]
        end = max(end, data[i][j])

# 1 4 0 2 1
# 0 0 5 6 3
# 8 4 7 2 0
# 7 1 0 5 3
# 4 5 7 9 1

# 85대 , 21 ->  9 분 85대 10분 85대 11 10000000분 85대


# 이진탐색
while start <= end:
    mid = (start + end) // 2
    answer = 0
    for i in range(n):
        for j in range(n):
            if data[i][j] >= mid:
                answer += mid
            else:
                answer += data[i][j]
    if sum / 2 > answer:
        start = mid + 1
    else:
        end = mid - 1

print(start)
