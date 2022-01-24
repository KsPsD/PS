import sys

input = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

N = int(input())

arr = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1]*N for _ in range(N)]


def go(y, x):
    if dp[y][x] != -1:
        return dp[y][x]

    dp[y][x] = 1
    for i in range(4):
        yy = y+dy[i]
        xx = x+dx[i]
        if yy < 0 or xx < 0 or yy >= N or xx >= N:
            continue
        if arr[yy][xx] > arr[y][x]:
            dp[y][x] = max(go(yy, xx)+1, dp[y][x])

    return dp[y][x]


ans = -1

for i in range(N):
    for j in range(N):
        ans = max(go(i, j), ans)


print(ans)
