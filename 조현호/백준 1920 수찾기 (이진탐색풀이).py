import sys
input = sys.stdin.readline

sort_num = int(input())
sort_data = sorted(list(map(int, input().split(' '))))
check_num = int(input())
check_data = list(map(int, input().split(' ')))

for i in range(check_num):
    start = 0
    end = sort_num - 1
    mid = (start + end) // 2
    answer = 0

    while(start <= end):
        if sort_data[mid] == check_data[i]:
            answer = 1
            break
        elif sort_data[mid] > check_data[i]:
            end = mid - 1
        elif sort_data[mid] < check_data[i]:
            start = mid + 1
        mid = (start + end) // 2

    print(answer)
