import sys
input = sys.stdin.readline

T = int(input())

while T:
    K = int(input())
    arr = list(map(int, input().split()))
    dp = [[0]*K for _ in range(K)]
    sum = {-1: 0}
    for i in range(K):
        sum[i] = sum[i-1]+arr[i]
    for i in range(1, K):
        for j in range(K-i):
            p = i+j
            dp[j][p] = sys.maxsize
            for k in range(j, p):
                dp[j][p] = min(dp[j][p],
                               dp[j][k]+dp[k+1][p]+sum[p]-sum[j-1])

    print(dp[0][-1])
    T -= 1
