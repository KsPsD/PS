import sys
from collections import deque

R, C = map(int, input().rstrip().split())

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# 문자열 한 줄 이런식으로 하면 됨
arr = [list(map(str, input())) for _ in range(R)]
ch = [[0] * C for _ in range(R)]
gsdc = deque()  # 고슴도치
water = deque()  # 물
cnt = 0

for i in range(R):
    for j in range(len(arr[i])):
        if arr[i][j] == 'S':
            gsdc.append((i, j))
            ch[i][j] = 1
        elif arr[i][j] == '*':
            water.append((i, j))


while len(gsdc) != 0:
    cur_loop = len(water)
    for i in range(cur_loop):
        tmp = water.popleft()
        for j in range(4):
            yy = tmp[0]+dy[j]
            xx = tmp[1]+dx[j]
            if yy < 0 or xx < 0 or yy >= R or xx >= C or arr[yy][xx] == 'X' or arr[yy][xx] == 'D' or arr[yy][xx] == '*':
                continue
            if arr[yy][xx] == '.':
                water.append((yy, xx))
                arr[yy][xx] = '*'

    cnt += 1  # 시간 증가

    # 고슴도치 움직이는 로직
    cur_loop = len(gsdc)
    # 큐에 있는 모든 경우를 다 돌아 봐야함
    for _ in range(cur_loop):
        cur = gsdc.popleft()
        for i in range(4):
            yy = cur[0]+dy[i]
            xx = cur[1]+dx[i]
            if yy < 0 or xx < 0 or yy >= R or xx >= C or arr[yy][xx] == 'X' or arr[yy][xx] == '*':
                continue
            if arr[yy][xx] == '.' and ch[yy][xx] == 0:
                gsdc.append((yy, xx))
                ch[yy][xx] = 1
            elif arr[yy][xx] == 'D':
                print(cnt)
                exit()

print("KAKTUS")
