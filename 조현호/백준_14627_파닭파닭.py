import sys
input = sys.stdin.readline

s, c = map(int, input().split())
length_list = []
for i in range(s):
    length_list.append(int(input()))

start = 1
end = 1_000_000_000
while start <= end:
    mid = (start + end)//2 # 치킨에 넣을 파의 길이
    temp = 0

    for length in length_list:
        if (length >= mid):
            temp += length // mid # 치킨에 들어갈 수 있는 파의 개수

    if (temp >= c):
        start = mid + 1
    else:
        end = mid - 1

print((sum(length_list) - end*c)) # 파의 총 길이에서 치킨에 들어가는 파를 뺀 값 출력