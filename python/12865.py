import sys

sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N, K = map(int, input().split())

item = [[] for _ in range(N+1)]

# dp = [0]*(K+1)

# dp = [[0] * (K+1) for _ in range(N+1)]

dp = [[-1] * (K+1) for _ in range(N+1)]

for i in range(1, N+1):
    w, v = map(int, input().split())
    item[i].append(w)
    item[i].append(v)
# 무게 뒤 부터 보면서 가능 한것 먼저 넣음 , 앞에서 넣으면 물건을 여러개 넣는 경우 생겨서 안됨
# for i in range(1, N+1):
#     for j in range(K, item[i][0]-1, -1):
#         dp[j] = max(dp[j], dp[j-item[i][0]]+item[i][1])

# 물건 N과 K일때 넣을 수 있고 없고로 계산
# for i in range(1, N+1):
#     for j in range(1, K+1):
#         if j >= item[i][0]:
#             dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i][0]] + item[i][1])
#         else:
#             dp[i][j] = dp[i-1][j]


def go(it, w):
    if it == N+1:
        return 0

    if dp[it][w] != -1:
        return dp[it][w]

    dp[it][w] = go(it+1, w)

    if w >= item[it][0]:
        dp[it][w] = max(dp[it][w], go(it+1, w-item[it][0]) + item[it][1])

    return dp[it][w]


print(go(1, K))
