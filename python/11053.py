import sys
from bisect import bisect_left
input = sys.stdin.readline


N = int(input())
maxi = -1
arr = list(map(int, input().rstrip().split()))

# dp = [0]*1000
dp = [-1]*1001

# for i in range(len(arr)):
#     dp[i] = 1
#     for j in range(i, -1, -1):
#         if arr[j] < arr[i] and dp[i] < dp[j]+1:
#             dp[i] = dp[j]+1

#     maxi = max(dp[i], maxi)

# print(maxi)
# 이진 탐색 풀이 훨씬 빠름
# LIS = []
# for ele in arr:
#     if LIS == [] or LIS[-1] < ele:
#         LIS.append(ele)
#     else:
#         idx = bisect_left(LIS, ele)
#         LIS[idx] = ele


# print(len(LIS))

# 재귀 풀이
# -1로 잡아줘서 for문 여러번 안 돌려도 됨
def go(start):
    if dp[start+1] != -1:
        return dp[start+1]

    dp[start+1] = 1

    for next in range(start+1, N):
        if start == -1 or arr[start] < arr[next]:
            dp[start+1] = max(dp[start+1], go(next)+1)

    return dp[start+1]


print(go(-1)-1)
