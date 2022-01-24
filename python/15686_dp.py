import sys

chicken = []
home = []
ans = sys.maxsize
ch = [0]*13


def calc():
    sum = 0
    for i in range(len(home)):
        dis = sys.maxsize
        for j in range(len(chicken)):
            if ch[j] == 1:
                dis = min(dis, abs(home[i][0] - chicken[j]
                                   [0]) + abs(home[i][1] - chicken[j][1]))

        sum += dis

    return sum


def go(now, trace):
    global ans
    if dp[now][trace]:
        return dp[now][trace]
    if trace == (1 << M)-1:
        ret = calc()
        return ret

    cost = sys.maxsize
    for i in range(len(chicken)):
        if (trace & (1 << i)) == 0:
            tmp = go(i, trace | (1 << i))
            cost = min(cost, tmp)


N, M = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]


for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            home.append((i, j))
        elif arr[i][j] == 2:
            chicken.append((i, j))

dp = [[0]*(1 << len(chicken)) for _ in range(len(chicken))]

go(0, 0)

print(ans)
