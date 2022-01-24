import sys
from collections import deque
input = sys.stdin.readline

dy = [0, 0, 1, -1, 0, 0]
dx = [1, -1, 0, 0, 0, 0]
dz = [0, 0, 0, 0, 1, -1]


# M이 열 N이 행
M, N, H = map(int, input().split())


arr = [[[] for _ in range(N)] for _ in range(H)]

flag = True
q = deque()


for k in range(H):
    for i in range(N):
        arr[k][i] = list(map(int, input().rstrip().split()))
        for j in range(len(arr[k][i])):
            if arr[k][i][j] == 1:
                q.append((k, i, j, 0))
            if arr[k][i][j] == 0:
                flag = False


if flag:
    print(0)
    exit(0)


cnt = 0
while q:
    tmp = q.popleft()
    if cnt < tmp[3]:
        cnt = tmp[3]
    for i in range(6):
        yy = tmp[1]+dy[i]
        xx = tmp[2]+dx[i]
        zz = tmp[0]+dz[i]
        if yy < 0 or xx < 0 or zz < 0 or yy >= N or xx >= M or zz >= H:
            continue
        if arr[zz][yy][xx] == 0:
            q.append((zz, yy, xx, cnt+1))
            arr[zz][yy][xx] = 1


for k in range(H):
    for i in range(N):
        for j in range(M):
            if arr[k][i][j] == 0:
                print(-1)
                exit(0)

print(cnt)
