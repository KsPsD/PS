import sys
input = sys.stdin.readline

N = int(input())

arr = [[0]*6 for _ in range(N+1)]
maxval = 0
maxidx = 0
dp = [[0, 0] for _ in range(N+1)]

for i in range(1, N+1):
    f, s = map(int, input().split())
    arr[i][f] = arr[i-1][f]+1
    if arr[i][f] > maxval:
        maxval = arr[i][f]
        maxidx = f
    elif arr[i][f] == maxval:
        if f < maxidx:
            maxidx = f
    if f != s:
        arr[i][s] = arr[i-1][s]+1
        if arr[i][s] > maxval:
            maxval = arr[i][s]
            maxidx = s
        elif arr[i][s] == maxval:
            if s < maxidx:
                maxidx = s

    dp[i] = [maxval, maxidx]

dp.sort(key=lambda x: (-x[0], x[1]))

print(f"{dp[0][0]} {dp[0][1]}")
