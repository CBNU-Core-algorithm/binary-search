import sys
input = sys.stdin.readline

input()
data = set(input().split())
input()
check_data = list(input().split())

print('\n'.join(list(map(lambda x: '1' if x in data else '0', [x for x in check_data]))))