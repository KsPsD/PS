import sys
from collections import deque


N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dy = [-1, -1, -1, 0, 1, 0, 1, 1]
dx = [-1, 0, 1, 1, 1, -1, 0, -1]


shark = deque()
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1:
            shark.append((i, j))

while shark:
    y, x = shark.popleft()
    for i in range(8):
        yy = y+dy[i]
        xx = x+dx[i]
        if 0 <= yy < N and 0 <= xx < M:
            if arr[yy][xx] == 0:
                shark.append((yy, xx))
                arr[yy][xx] = arr[y][x]+1


ans = 0

for i in range(N):
    for j in range(M):
        ans = max(ans, arr[i][j])

print(ans-1)
