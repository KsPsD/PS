import sys

input = sys.stdin.readline


N = int(input())

dp = [-1]*91


def dfs(N):
    if N == 0:
        dp[N] = 0
        return dp[N]
    if N == 1:
        dp[N] = 1
        return dp[N]
    if dp[N] != -1:
        return dp[N]

    dp[N] = 0

    dp[N] = dfs(N-1)+dfs(N-2)
    return dp[N]


print(dfs(N))
