import sys
# sys.stdin = open('a.txt', 'rt') # test입력용 코드
input = sys.stdin.readline

# 입력
n = int(input())
arr = list(map(int, input().split()))
m = int(input())


l = 0
r = max(arr)

while l <= r:
    temp = 0
    mid = (l + r) // 2
    # 상한선이 mid 일 때의 필요한 예산 구하기
    for i in arr:
        if i > mid:
            temp += mid
        else:
            temp += i

    if temp <= m:
        l = mid + 1
    else:
        r = mid - 1

print(r)
