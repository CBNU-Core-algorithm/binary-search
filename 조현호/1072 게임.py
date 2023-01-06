import sys

x, y = map(int, sys.stdin.readline().split())
# z = int(y * 100 / x) # 이렇게 적으면 오류가 난다. https://ahn3330.tistory.com/110
z = y * 100 // x

start = 0
end = 1_000_000_000
mid = (start + end) // 2 # 추가로 해야하는 게임 횟수

if z >= 99:
    print(-1)
else:
    while start <= end:
        mid = (start + end) // 2
        check = (y + mid) * 100 // (x + mid)
        # print(start, mid, end)

        if z != check:
            end = mid - 1
        elif z == check:
            start = mid + 1

    print(start)
