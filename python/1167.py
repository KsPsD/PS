from collections import defaultdict
from collections import deque

import sys
input = sys.stdin.readline
arr = defaultdict(list)


V = int(input())
ch = [0]*(V+1)
dist = [0]*(V+1)


def bfs(start):
    global ch, dist
    ch = [0]*(V+1)
    dist = [0]*(V+1)
    q = deque()
    ch[start] = 1
    q.append(start)
    while q:
        cur = q.popleft()
        for next in arr[cur]:
            if ch[next[0]] == 0:
                dist[next[0]] = dist[cur]+next[1]
                q.append(next[0])
                ch[next[0]] = 1


for i in range(V):
    idx, *lst, end = map(int, input().split())
    for j in range(0, len(lst)//2):
        arr[idx].append((lst[2*j], lst[2*j+1]))
        arr[lst[2*j]].append((idx, lst[2*j+1]))


bfs(1)
start = 1
for i in range(1, V+1):
    if dist[i] > dist[start]:
        start = i


bfs(start)


ans = max(dist)
print(ans)
