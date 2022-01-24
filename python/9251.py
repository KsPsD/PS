import sys

input = sys.stdin.readline

A = input().rstrip()
B = input().rstrip()

MAX = 1001
dp = [[0]*(MAX) for _ in range(MAX)]

for i in range(len(A)):
    for j in range(len(B)):
        if A[i] == B[j]:
            dp[i][j] = dp[i-1][j-1]+1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])


print(dp[len(A)-1][len(B)-1])
