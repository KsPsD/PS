import sys

input = sys.stdin.readline

T = int(input())

dp = [0] * 100001

dp[1] = 1
dp[2] = 2
dp[3] = 2
dp[4] = 3
dp[5] = 3
dp[6] = 6

for i in range(7, 100001):
    dp[i] = (dp[i-2]+dp[i-6]+dp[i-4]) % 1000000009

for i in range(T):
    val = int(input())
    print(dp[val])
