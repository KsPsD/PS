import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
arr = defaultdict(list)
ch = [0]*(N+1)
dist = [0]*(N+1)


def bfs(start):
    global ch, dist
    ch = [0]*(N+1)
    dist = [0]*(N+1)
    q = deque()
    q.append(start)
    ch[start] = 1

    while q:
        cur = q.popleft()
        for next in arr[cur]:

            if ch[next[0]] == 0:
                ch[next[0]] = 1
                q.append(next[0])
                dist[next[0]] = dist[cur]+next[1]


for i in range(N-1):
    s, e, cost = map(int, input().split())
    arr[s].append([e, cost])
    arr[e].append([s, cost])


bfs(1)
start = 1


for i in range(1, N+1):
    if dist[i] > dist[start]:
        start = i

bfs(start)


ans = max(dist)

print(ans)
