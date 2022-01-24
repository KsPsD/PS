import sys
from collections import deque
import math
input = sys.stdin.readline

M, N = map(int, input().split())

arr = [list(map(str, input().rstrip())) for _ in range(N)]
ch = [[0]*M for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


white = 0
blue = 0
maxi = -1


def bfs(y, x, cnt):
    global maxi
    q = deque()
    ch[y][x] = 1
    cnt += 1
    q.append((y, x))
    flag = None
    if arr[y][x] == 'W':
        flag = True
    else:
        flag = False
    while q:

        tmp = q.popleft()
        # maxi = max(maxi, cnt)
        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= N or xx >= M:
                continue
            if flag == True:
                if arr[yy][xx] == 'W' and ch[yy][xx] == 0:
                    ch[yy][xx] = 1
                    q.append((yy, xx))
                    cnt += 1
                else:
                    continue
            else:
                if arr[yy][xx] == 'B' and ch[yy][xx] == 0:
                    ch[yy][xx] = 1
                    q.append((yy, xx))
                    cnt += 1
                else:
                    continue
    # cnt = maxi
    return cnt


for i in range(N):
    for j in range(M):
        if ch[i][j] == 0:
            cnt = 0
            maxi = 0
            cnt = bfs(i, j, cnt)
            if arr[i][j] == 'W':
                white += cnt**2
            else:
                blue += cnt**2


print(white, blue)
