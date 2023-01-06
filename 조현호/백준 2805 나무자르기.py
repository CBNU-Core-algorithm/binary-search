import sys
input = sys.stdin.readline

n, m = list(map(int, input().split(' ')))
height_list = list(map(int, input().split(' ')))

start = 0
end = max(height_list)
has_tree = 0

while start <= end:
    mid = (start + end) // 2
    has_tree = 0

    for height in height_list:
        if height > mid:
            has_tree = has_tree + (height - mid)
        if has_tree > m:
            break

    if has_tree >= m:
        start = mid + 1
    else:
        end = mid - 1

print(end)
