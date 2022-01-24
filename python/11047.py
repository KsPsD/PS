import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]

cur = K
cnt = 0
for num in reversed(arr):
    if num <= cur:
        val = cur//num
        cnt += val
        cur = cur-(num*val)
print(cnt)
