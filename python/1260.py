import sys
from collections import deque
input = sys.stdin.readline


N, M, V = map(int, input().split())

arr = [[] for _ in range(1001)]

ch = [0]*(1001)

bfs_ans = []


def dfs(node, level):
    print(node, end=" ")
    ch[node] = 1
    if level == N:
        return

    for ele in arr[node]:
        if ch[ele] == 0:
            dfs(ele, level+1)


def bfs(node):
    q = deque()
    ch[node] = 1
    q.append(node)
    while q:
        tmp = q.popleft()
        print(tmp, end=" ")
        for ele in arr[tmp]:
            if ch[ele] == 0:
                q.append(ele)
                ch[ele] = 1


for i in range(M):
    s, e = map(int, input().split())
    arr[s].append(e)
    arr[e].append(s)

for i in range(1, N+1):
    arr[i].sort()

dfs(V, 0)
ch = [0]*(N+1)
print()
bfs(V)
