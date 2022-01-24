import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dp = [[[0 for _ in range(K+1)] for _ in range(M+1)]for _ in range(N+1)]

for i in range(N):
    for j in range(1, M+1):
        for k in range(1, K+1):
            if j >= arr[i][0] and k >= arr[i][1]:
                dp[i][j][k] = max(dp[i-1][j][k], dp[i-1]
                                  [j-arr[i][0]][k-arr[i][1]] + 1)
            else:
                dp[i][j][k] = dp[i-1][j][k]

print(dp[N-1][M][K])
