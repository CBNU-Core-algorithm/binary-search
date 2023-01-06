import sys

# sys.stdin = open('a.txt', 'rt') # test입력용 코드
input = sys.stdin.readline

# 입력
n = int(input())
arr = list(map(int, input().split()))

lis = [arr[0]] # 최장증가수열(LIS) 리스트
for item in arr:
    if lis[-1] < item:
        lis.append(item)
    else:
        l = 0
        r = len(lis) - 1

        # 이진탐색 - lower bound (처음으로 크거나같은 값의 인덱스)
        while l < r:
            mid = (l + r) // 2
            if lis[mid] < item:
                l = mid + 1
            else:
                r = mid
        lis[r] = item

# print(lis)
print(len(lis))
