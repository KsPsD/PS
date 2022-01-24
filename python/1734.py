import sys
from collections import deque
import math
input = sys.stdin.readline


N, M, K = map(int, input().split())
arr = [['.']*M for _ in range(N)]
ch = [[0]*M for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

for i in range(K):
    y, x = map(int, input().split())
    y -= 1
    x -= 1
    arr[y][x] = '#'


def bfs(y, x):
    q = deque()
    cnt = 1
    ch[y][x] = 1
    q.append((y, x))
    max_cnt = -1
    while q:
        tmp = q.pop()

        # max_cnt = max(cnt, max_cnt)
        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1] + dx[i]
            if yy < 0 or xx < 0 or xx >= M or yy >= N:
                continue
            if ch[yy][xx] == 0 and arr[yy][xx] == '#':
                ch[yy][xx] = 1
                cnt += 1
                q.append((yy, xx))
    return cnt


maxi = -1
for i in range(N):
    for j in range(M):
        if ch[i][j] == 0 and arr[i][j] == '#':

            maxi = max(bfs(i, j), maxi)


print(maxi)
