from collections import deque
import sys
input = sys.stdin.readline


N = int(input().rstrip())
M = int(input().rstrip())

arr = [[0] * (N+1) for _ in range(N+1)]
ch = [0]*(N+1)
dp = [0]*(N+1)


def go(node):
    if ch[node] != -1:
        return 1

    else:
        ret = 0
        for i in range(1, N+1):
            if arr[node][i] != 0:
                dp[node][i] = arr[node][i] * go(i)
                # for j in range(1, arr[node][i]+1):
                #     dp[node][i] += go(i)
        for i in range(1, N+1):
            ret += dp[node][i]
    return ret


for i in range(M):
    s, e, val = map(int, input().rstrip().split())
    arr[s][e] = val
    ch[s] = -1

go(N)

for i in range(1, N+1):
    if ch[i] != -1:
        print(ch[i])
