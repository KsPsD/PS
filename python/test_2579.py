import sys
input = sys.stdin.readline

N = int(input())

arr = [0]+[int(input()) for _ in range(N)]
dp = [-1]*(N+1)

dp[0] = 0


def go(cur):
    if dp[cur] != -1:
        return dp[cur]

    if cur == 0:
        return 0

    if cur == 1:
        dp[1] = arr[1]
        return dp[1]

    if cur == 2:
        return arr[1]+arr[2]

    dp[cur] = 0
    dp[cur] = max(go(cur-3)+arr[cur-1], go(cur-2))+arr[cur]

    return dp[cur]


print(go(N))
