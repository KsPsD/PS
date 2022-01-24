import sys
input = sys.stdin.readline

N, M = map(int, input().split())

dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]

di_y = [-1, -1, 1, 1]
di_x = [-1, 1, 1, -1]
cloud = []
arr = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, input().split()))

cmd = []
for _ in range(M):
    d, len = map(int, input().split())
    cmd.append([d-1, len])


cloud.append([N-1, 0])
cloud.append([N-1, 1])
cloud.append([N-2, 0])
cloud.append([N-2, 1])

for dir in range(M):
    ch = [[0]*N for _ in range(N)]
    moved = []
    while cloud:
        y, x = cloud.pop(0)

        yy = (y+dy[cmd[dir][0]]*cmd[dir][1]) % N
        xx = (x+dx[cmd[dir][0]]*cmd[dir][1]) % N
        ch[yy][xx] = 1
        arr[yy][xx] += 1
        moved.append([yy, xx])
    for mv in moved:
        y = mv[0]
        x = mv[1]
        for d in range(4):
            yy = y+di_y[d]
            xx = x+di_x[d]
            if yy < 0 or xx < 0 or yy >= N or xx >= N:
                continue
            if arr[yy][xx] != 0:
                arr[y][x] += 1
    for i in range(N):
        for j in range(N):
            if ch[i][j] != 1 and arr[i][j] >= 2:
                cloud.append([i, j])
                arr[i][j] -= 2

ans = 0
for i in range(N):
    for j in range(N):
        ans += arr[i][j]


print(ans)
