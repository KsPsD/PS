from collections import deque
import sys
input = sys.stdin.readline
R, C = map(int, input().rstrip().split())
ch = [0]*26

arr = [list(map(str, input().rstrip())) for _ in range(R)]
cnt = 0
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
maxi = -sys.maxsize


def bfs(y, x, alpha):
    global maxi
    q = set()
    q.add((y, x, alpha))
    while q:
        tmp = q.pop()
        maxi = max(maxi, len(tmp[2]))

        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= R or xx >= C:
                continue
            if arr[yy][xx] not in tmp[2]:
                q.add((yy, xx, tmp[2]+arr[yy][xx]))


bfs(0, 0, arr[0][0])

print(maxi)
