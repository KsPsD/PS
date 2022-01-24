import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)


N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1]*M for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def go(y, x):
    if dp[y][x] != -1:
        return dp[y][x]

    if y == N-1 and x == M-1:
        return 1

    dp[y][x] = 0

    for i in range(4):
        yy = y+dy[i]
        xx = x+dx[i]
        if yy < 0 or xx < 0 or yy >= N or xx >= M:
            continue
        if arr[y][x] > arr[yy][xx]:
            dp[y][x] += go(yy, xx)

    return dp[y][x]


print(go(0, 0))
