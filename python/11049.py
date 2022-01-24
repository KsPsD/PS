import sys
input = sys.stdin.readline
n = int(input())
s = [list(map(int, input().split())) for i in range(n)]
dp = [[0] * n for i in range(n)]
for gap in range(1, n):
    for start in range(n - gap):
        x = start + gap
        dp[j][x] = 2 ** 32
        for mid in range(start, x):
            dp[j][x] = min(dp[start][x], dp[start][mid] + dp[mid + 1]
                           [x] + s[start][0] * s[mid][1] * s[x][1])
print(dp[0][n - 1])
