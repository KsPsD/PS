import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)


T = int(input())
N, K = None, None
time = None
arr = None
in_ = None
dp = None


def go(des):
    if dp[des] != -1:
        return dp[des]
    # if des == 0:
    #     return time[des]

    t = 0
    for i in range(1, N+1):
        if arr[i][des] == 1:
            t = max(t, go(i))
    dp[des] = t + time[des]
    return dp[des]


for _ in range(T):
    N, K = map(int, input().split())
    time = [0]+list(map(int, input().split()))
    arr = [[0] * (N+1) for _ in range(N+1)]
    in_ = [0] * (N+1)
    dp = [-1] * (N+1)

    for i in range(K):
        s, e = map(int, input().split())
        arr[s][e] = 1

    W = int(input())

    print(go(W))
