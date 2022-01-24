import sys
import heapq
input = sys.stdin.readline


n = 6
s = 4
a = 6
b = 2
fares = [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [
    5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]


# arr = [[sys.maxsize]*(n+1) for _ in range(n+1)]

dist = [[sys.maxsize] * (n+1) for _ in range(n+1)]


for i in range(len(fares)):
    dist[fares[i][0]][fares[i][1]] = fares[i][2]
    dist[fares[i][1]][fares[i][0]] = fares[i][2]
# print(dist)
for i in range(1, n+1):
    dist[i][i] = 0


for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if dist[i][j] > dist[i][k]+dist[k][j]:
                dist[i][j] = dist[i][k]+dist[k][j]


ans = sys.maxsize
for i in range(1, n+1):
    if ans > dist[s][i]+dist[i][a]+dist[i][b]:
        ans = dist[s][i]+dist[i][a]+dist[i][b]

print(ans)
