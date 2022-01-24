import sys
from collections import deque
input = sys.stdin.readline


N = int(input())
M = int(input())
arr = [[] for _ in range(N+1)]
ch = [0] * (N+1)

cnt = 0


def dfs(node):
    global cnt
    for ele in arr[node]:
        if ch[ele] == 1:
            continue
        ch[ele] = 1
        cnt += 1
        dfs(ele)


for i in range(M):

    s, e = map(int, input().split())
    arr[s].append(e)
    arr[e].append(s)


ch[1] = 1

dfs(1)


print(cnt)
