from collections import deque
import sys
input = sys.stdin.readline

# M 열 N행
t = int(input())


dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x):
    q = deque()
    ch[y][x] = 1
    q.append((y, x))
    while q:
        tmp = q.popleft()
        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= N or xx >= M:
                continue
            if arr[yy][xx] == 1 and ch[yy][xx] == 0:
                ch[yy][xx] = 1
                q.append((yy, xx))


for _ in range(t):
    cnt = 0
    M, N, K = map(int, input().rstrip().split())
    ch = [[0]*M for _ in range(N)]
    arr = [[0]*M for _ in range(N)]

    for _ in range(K):
        x, y = map(int, input().split())
        arr[y][x] = 1

    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1 and ch[i][j] != 1:
                bfs(i, j)
                cnt += 1

    print(cnt)
