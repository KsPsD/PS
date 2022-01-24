import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)


N, M = map(int, input().split())
MAX = 10001
dp = [[-1]*140 for i in range(MAX)]
ch = [0 for i in range(N+1)]
flag = False
for i in range(M):
    idx = int(input())
    ch[idx] = 1


def go(idx, jump):
    global flag
    if idx == N:
        flag = True
        return 0

    if dp[idx][jump] != -1:
        return dp[idx][jump]

    dp[idx][jump] = sys.maxsize
    for i in range(-1, 2):
        if jump+i >= 1:
            next = idx+(jump+i)
            if next <= N and ch[next] != 1:
                dp[idx][jump] = min(dp[idx][jump], 1+go(next, jump+i))

    return dp[idx][jump]


res = go(1, 0)

if flag:
    print(res)
else:
    print(-1)
