from collections import deque
import sys
input = sys.stdin.readline

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x):
    ch = [[0]*N for _ in range(N)]
    fish = []
    time = [[0]*N for _ in range(N)]
    q = deque()
    ch[y][x] = 1
    q.append([y, x])
    while q:

        a, b = q.popleft()
        for i in range(4):
            yy = a+dy[i]
            xx = b+dx[i]
            if yy < 0 or yy >= N or xx < 0 or xx >= N:
                continue
            if ch[yy][xx] == 0:
                if arr[yy][xx] <= arr[y][x] or arr[yy][xx] == 0:
                    q.append([yy, xx])
                    ch[yy][xx] = 1
                    time[yy][xx] = time[a][b]+1
                if arr[yy][xx] < arr[y][x] and arr[yy][xx] != 0:
                    fish.append([yy, xx, time[yy][xx]])

    if not fish:
        return -1, -1, -1
    fish.sort(key=lambda x: (x[2], x[0], x[1]))
    return fish[0][0], fish[0][1], fish[0][2]


N = int(input())
arr = []
for i in range(N):
    a = list(map(int, input().split()))
    arr.append(a)
    for j in range(N):

        if a[j] == 9:
            arr[i][j] = 2
            start = [i, j]


cnt = 0
ans = 0
while 1:
    y, x = start[0], start[1]
    yy, xx, time = bfs(y, x)

    if yy == -1:
        break

    arr[yy][xx] = arr[y][x]
    arr[y][x] = 0
    start = [yy, xx]
    cnt += 1
    if cnt == arr[yy][xx]:
        cnt = 0
        arr[yy][xx] += 1
    ans += time

print(ans)
