import sys
input = sys.stdin.readline


T = int(input())
dp = [0]*11


# 반복문 사용한 dp

# dp[1] = 1
# dp[2] = 2
# dp[3] = 4

# for i in range(4, 11):
#     for j in range(1, 4):
#         dp[i] += dp[i-j]

# for i in range(T):
#     num = int(input())
#     print(dp[num])

# 재귀를 사용한 dp
def go(n):  # 기본이 되는 수들 지정해 놓음 1,2,3 값들
    if n == 1:
        dp[1] = 1
        return dp[1]
    if n == 2:
        dp[2] = 2
        return dp[2]
    if n == 3:
        dp[3] = 4
        return dp[3]

    if dp[n] != 0:
        return dp[n]

    dp[n] = go(n-1)+go(n-2)+go(n-3)

    return dp[n]  # dp배열에 값을 바로 저장해서 결과 보여줌


for i in range(T):
    num = int(input())
    print(go(num))
