import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**5)

N, M = map(int, input().split())

arr = [input() for _ in range(N)]
ch = [[0] * M for _ in range(N)]
dist = [[0]*M for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
flag = False


def dfs(y, x, cnt, color):
    global flag
    if(ch[y][x]):
        if cnt-dist[y][x] >= 4:
            return True
        else:
            return False

    ch[y][x] = True
    dist[y][x] = cnt
    for i in range(4):
        yy = dy[i]+y
        xx = dx[i]+x
        if 0 <= yy < N and 0 <= xx < M:
            if(arr[yy][xx] == color):
                if(dfs(yy, xx, cnt+1, color)):
                    return True


for i in range(N):
    for j in range(M):
        if ch[i][j] == 0:
            if dfs(i, j, 1, arr[i][j]):
                print("Yes")
                exit(0)

print("No")
