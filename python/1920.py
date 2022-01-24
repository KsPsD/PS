from bisect import bisect_left, bisect_right
import sys
input = sys.stdin.readline


# def search(target):
#     l = 0
#     r = N-1
#     flag = False
#     while l <= r:
#         mid = (l+r)//2
#         if arr[mid] == target:
#             return 1
#         elif arr[mid] <= target:
#             l = mid+1
#         elif arr[mid] > target:
#             r = mid-1


#     return 0


N = int(input())

arr = input().rstrip().split()
arr.sort()

M = int(input())


target = input().rstrip().split()

for i in range(M):
    val = bisect_left(arr, target[i])
    if val < N and arr[val] == target[i]:
        print(1)
    else:
        print(0)
