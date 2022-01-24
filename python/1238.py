import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline

N, M, X = map(int, input().split())
g = defaultdict(dict)


def find(start, end):
    dist = {node: float('inf') for node in g}
    dist[start] = 0
    q = []
    heapq.heappush(q, [dist[start], start])

    while q:
        cur_dis, cur_des = heapq.heappop(q)

        if dist[cur_des] < cur_dis:
            continue

        for new_des, new_dis in g[cur_des].items():
            distance = cur_dis + new_dis
            if distance < dist[new_des]:
                dist[new_des] = distance
                heapq.heappush(q, [distance, new_des])

    return dist[end]


for i in range(M):
    s, e, v = map(int, input().split())
    g[s][e] = v

maxi = -1

for stu in range(1, N+1):
    go = find(stu, X)
    back = find(X, stu)
    dist = go+back
    maxi = max(dist, maxi)

print(maxi)
