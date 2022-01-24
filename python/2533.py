import sys
from collections import defaultdict
input = sys.stdin.readline

sys.setrecursionlimit(10**8)
N = int(input())

tree = defaultdict(list)
dp = [[0]*2 for _ in range(N+1)]
ch = [0]*(N+1)


def go(cur):
    ch[cur] = 1
    dp[cur][0] = 0
    dp[cur][1] = 1
    for next in tree[cur]:
        if ch[next] == 1:
            continue

        go(next)

        dp[cur][0] += dp[next][1]
        dp[cur][1] += min(dp[next][0], dp[next][1])


for i in range(N-1):
    k, v = map(int, input().split())
    tree[k].append(v)
    tree[v].append(k)


go(1)

print(min(dp[1][0], dp[1][1]))
