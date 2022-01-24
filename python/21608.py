import sys
input = sys.stdin.readline

N = int(input())

num = (N**2)
arr = [[0] * 4 for _ in range((num)+1)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
order = []


room = [[0] * N for _ in range(N)]


def findfriends(i, j):
    pass


l


def findblank(y, x):
    for i in range(4):
        yy = y+dy[i]
        xx = x+dx[i]
        if yy < 0 or xx < 0 or yy >= N or xx >= N:
            continue
        if arr[yy][xx] == 0:

            cnt += 1


def sim(stu):
    for y in range(N):
        for x in range(N):
            max_f = -1
            if room[y][x] == 0:
                cnt = 0
                seat = []
                for i in range(4):
                    yy = y+dy[i]
                    xx = x+dx[i]
                    if yy < 0 or xx < 0 or yy >= N or xx >= N:
                        continue
                    if arr[yy][xx] != 0 and arr[yy][xx] in order:
                        cnt += 1
                if max_f < cnt:
                    if len(seat) != 0:
                        seat.pop()
                    max_f = cnt
                    seat.append([y, x])
    if len(arr) != 1:
        for cand in seat:
            findblank(cand[0], cand[1])


for i in range(num):
    in_, *like = map(int, input().split())
    arr[in_] = like
    order.append(in_)

cnt = 0

room[1][1] = order[0]

for i in order[1:]:
    sim(i)
