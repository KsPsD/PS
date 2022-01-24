import sys
import copy
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
ch = [[0]*M for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
cheese = []
time = 0
MELT = 'M'
AROUND = 'A'

# 외부 공기를 찾는 과정


def sep_air():
    ch = [[0]*M for _ in range(N)]

    q = deque()
    q.append((0, 0))
    ch[0][0] = 1
    while q:
        cur = q.popleft()
        for i in range(4):
            yy = cur[0]+dy[i]
            xx = cur[1] + dx[i]
            if yy < 0 or xx < 0 or yy >= N or xx >= M:
                continue
            if ch[yy][xx] == 0 and arr[yy][xx] != 1:
                ch[yy][xx] = 1
                arr[yy][xx] = AROUND
                q.append((yy, xx))

# 주변 공기를 세서 치즈를 녹여주는 과정


def melting():
    global time
    flag = False

    while 1:

        sep_air()

        flag = False
        for i in range(N):
            for j in range(M):
                if arr[i][j] == 1:
                    cnt = 0
                    for k in range(4):
                        yy = i+dy[k]
                        xx = j+dx[k]
                        if yy >= 0 and xx >= 0 and yy < N and xx < M and arr[yy][xx] == AROUND:
                            flag = True
                            cnt += 1

                    if cnt >= 2:
                        arr[i][j] = MELT

        # 치즈를 녹인 경우가 있다면 찾아서 녹여줌
        if flag:
            for i in range(N):
                for j in range(M):
                    if arr[i][j] == MELT:
                        arr[i][j] = 0
        time += 1
        flag = False
        # 돌지 않은 치즈 확인
        for i in range(N):
            for j in range(M):
                if arr[i][j] == 1:
                    flag = True

        if not flag:
            break


melting()
print(time)
