import sys
# sys.stdin = open('b.txt', 'rt') # test용 코드

def convert_to_list(input_ms):
    converted_list = []
    for i in range(len(input_ms)):
        if input_ms[i] != 'n':
            # g일때 전이 n 이었으면 continue
            if input_ms[i] == 'g' and i >= 1 and input_ms[i - 1] == 'n':
                continue

            converted_list.append(input_ms[i])
            continue

        # n 다음에 g가 올 경우 / 인덱스 초과 방지를 위해 인덱스 끝 값이면 다음인덱스 비교 x
        if input_ms[i] == 'n' and i < len(input_ms) - 1 and input_ms[i + 1] == 'g':
            converted_list.append(input_ms[i:i + 2])
        else:
            converted_list.append(input_ms[i])

    return converted_list

def compare(input_ms_1, input_ms_2, order_dict):
    limit = min(len(input_ms_1), len(input_ms_2))
    cnt = 0

    # 둘이 다른 구간 나올때 까지만 반복
    for i in range(limit):
        if order_dict[input_ms_1[i]] == order_dict[input_ms_2[i]]:
            cnt += 1
            continue
        else:
            break

    # 순서가 더 크고 길이가 긴 쪽이 뒤에 온다.
    if cnt == limit:
        sorted_list = [input_ms_2, input_ms_1] if len(input_ms_1) >= len(input_ms_2) else [input_ms_1, input_ms_2]
    else:
        sorted_list = [input_ms_2, input_ms_1] if order_dict[input_ms_1[cnt]] >= order_dict[input_ms_2[cnt]] else [input_ms_1, input_ms_2]
    return sorted_list



# 값 입력 받기 / 입력받은 값은 바로 민식이어에 맞게 리스트로 변환해서 저장
n = int(sys.stdin.readline().strip())
input_ms_list = []
for _ in range(n):
    input_ms_list.append(convert_to_list(sys.stdin.readline().strip()))

# 딕셔너리 형태로 민식어 순서 저장
ms_sorted = 'a b k d e g h i l m n ng o p r s t u w y'.split()
ms_dict = {}
for i, x in enumerate(ms_sorted):
    ms_dict[x] = i

# 정렬하기
for i in range(len(input_ms_list)):
    for j in range(i + 1, len(input_ms_list)):
        front, rear = compare(input_ms_list[i], input_ms_list[j], ms_dict)
        input_ms_list[i] = front
        input_ms_list[j] = rear

# 출력하기
for ms_list in input_ms_list:
    print(''.join(x for x in ms_list))




