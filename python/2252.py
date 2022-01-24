from collections import deque
import sys
input = sys.stdin.readline


N, M = map(int, input().rstrip().split())

arr = [[] for _ in range(N+1)]
ch = [0] * (N+1)
st = []


def dfs(node):
    ch[node] = 1
    for next in arr[node]:
        if ch[next] == 0:
            dfs(next)

    st.append(node)


for i in range(M):
    s, e = map(int, input().rstrip().split())
    arr[s].append(e)


for i in range(1, N+1):
    if ch[i] == 0:
        dfs(i)

print(*list(reversed(st)))
