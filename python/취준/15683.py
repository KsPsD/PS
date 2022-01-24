import sys
import copy
input = sys.stdin.readline
INF = int(1e9)

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
cnt = 0
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
direction = [[], [[0], [1], [2], [3]], [[0, 1], [2, 3]], [[0, 2], [2, 1], [1, 3], [3, 0]],
             [[3, 0, 2], [1, 3, 0], [0, 2, 1], [2, 1, 3]], [[0, 1, 2, 3]]]

cctv = []
ans = INF


def makeArea(y, x, dir, tmp):
    for d in dir:
        xx = x
        yy = y
        while 1:
            xx += dx[d]
            yy += dy[d]
            if xx >= 0 and xx < M and yy >= 0 and yy < N and tmp[yy][xx] is not 6:
                if tmp[yy][xx] is 0:
                    tmp[yy][xx] = "#"
            else:
                break


def dfs(arr, cur_cnt):
    global ans
    tmp = copy.deepcopy(arr)
    if cur_cnt == cnt:
        c = 0
        for i in tmp:
            c += i.count(0)
        ans = min(c, ans)
        return
    y, x, num = cctv[cur_cnt]
    for i in direction[num]:
        makeArea(y, x, i, tmp)
        dfs(tmp, cur_cnt+1)
        tmp = copy.deepcopy(arr)


for i in range(N):
    for j in range(M):
        if(1 <= arr[i][j] <= 5):
            cnt += 1
            cctv.append([i, j, arr[i][j]])


dfs(arr, 0)

print(ans)
