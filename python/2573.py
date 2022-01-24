import sys
from collections import deque
import copy
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

arr = [list(map(int, input().rstrip().split())) for _ in range(N)]
ch = [[0] * M for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x):
    global arr
    q = deque()
    q.append((y, x))
    ch[y][x] = 1
    new_arr = copy.deepcopy(arr)
    while q:
        tmp = q.pop()
        cnt = 0
        for i in range(4):
            yy = tmp[0]+dy[i]
            xx = tmp[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= N or xx >= M:
                continue
            if arr[yy][xx] == 0:
                cnt += 1
            elif arr[yy][xx] != 0 and ch[yy][xx] == 0:
                ch[yy][xx] = 1
                q.append((yy, xx))
        new_arr[tmp[0]][tmp[1]] = arr[tmp[0]][tmp[1]] - \
            cnt if arr[tmp[0]][tmp[1]]-cnt > 0 else 0
    arr = new_arr


time = 0  # 걸리는 시간
while 1:
    ch = [[0] * M for _ in range(N)]
    num = 0  # 섬 갯수
    for i in range(1, N):
        for j in range(1, M):
            if arr[i][j] != 0 and ch[i][j] == 0:
                bfs(i, j)
                num += 1

    if num > 1:
        print(time)
        break
    elif num == 0:
        print(0)
        break
    time += 1
