# # 내 풀이
# x = int(int(n:=int(input()))**0.5)
#
# if n > x*x:
#     print(x+1)
# else:
#     print(x)
#
#
# #2 이진검색 활용 풀이
# import sys

n = int(input())

start, end = 0, n

while start <= end:
    mid = (start+end) // 2
    if mid**2 < n:
        start = mid+1
    else:
        end = mid-1
    print(start, mid, end)
print(start)

#
#
# #3 숏코딩
# n=int(input())
# p=int(n**.5)
# print(p+(p*p<n))