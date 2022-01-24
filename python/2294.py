import sys
input = sys.stdin.readline

n, k = map(int, input().split())

arr = []

dp = [10001] * (k + 1)
dp[0] = 0
for _ in range(n):
    arr.append(int(input()))
arr.sort()


for ele in arr:
    for j in range(ele, k+1):  # j원을 거슬러 주는데 사용한 동전의 최소 갯수
        dp[j] = min(dp[j], dp[j-ele]+1)


if dp[k] == 10001:
    print(-1)
else:
    print(dp[k])
