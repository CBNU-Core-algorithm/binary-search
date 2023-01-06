def solution(n, times):
    start = 1
    end = 1e18 # 모든 사람이 심사를 받는데 걸리는 시간의 최댓값

    while start <= end:
        mid = (start + end) // 2
        people = 0
        for time in times:
            people += mid // time
            if people >= n:
                break

        if people >= n:
            end = mid - 1

        elif people < n:
            start = mid + 1

    return start

result = solution(6, [7, 10])
print(f'answer: {result}')