import sys


def go(now, trace):
    if dp[now][trace]:
        return dp[now][trace]

    # 기저 조건
    if trace == (1 << N)-1:
        return path[now][0] if path[now][0] > 0 else MAX

    # 각 상태에서 구해야하는 값
    cost = MAX
    for i in range(1, N):
        if not trace & (1 << i) and path[now][i]:
            val = go(i, trace | (1 << i))
            cost = min(cost, val+path[now][i])

    # dp에 값 갱신
    dp[now][trace] = cost
    return dp[now][trace]


N = int(input())
path = [list(map(int, input().split())) for _ in range(N)]
dp = [[0] * (1 << N) for _ in range(N)]
MAX = sys.maxsize

# print(dp)
print(go(0, 1))
