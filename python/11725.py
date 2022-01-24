import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10**8)


N = int(input().rstrip())
arr = [[] for _ in range(N+1)]
trace = [0]*(N+1)
ch = [0]*(N+1)


for i in range(N-1):
    s, e = map(int, input().rstrip().split())
    arr[s].append(e)
    arr[e].append(s)


def go(node):
    for next in arr[node]:
        if ch[next] == 0:
            trace[next] = node
            ch[next] = 1
            go(next)


ch[1] = 1
go(1)

for i in range(2, N+1):
    print(trace[i])
