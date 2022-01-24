import sys

from collections import deque

q = deque()

N = int(input())

arr = [input().rstrip() for _ in range(N)]

ch = [[0]*N for _ in range(N)]

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


res = []


def bfs(i, j, cnt):

    q = deque()
    q.append((i, j))
    ch[i][j] = 1
    while q:
        tmp = q.pop()
        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= N or xx >= N:
                continue
            if ch[yy][xx] == 0 and arr[yy][xx] == '1':
                ch[yy][xx] = 1
                q.append((yy, xx))

                cnt += 1

    return cnt


for i in range(N):
    for j in range(N):
        if ch[i][j] == 0 and arr[i][j] == '1':
            cnt = bfs(i, j, 1)
            res.append(cnt)

res.sort()
print(len(res))
for i in res:
    print(i)
