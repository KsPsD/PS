import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
time = 0
arr = [[0]*(N) for _ in range(N)]

apple = []
idx = 0
snake = deque()
y, x = 0, 0
snake.append([y, x])
arr[y][x] = 2
d = 0


def find(dd, cmd):
    if cmd == "L":
        if dd == 0:
            return 3
        elif dd == 1:
            return 0
        elif dd == 2:
            return 1
        elif dd == 3:
            return 2
    else:
        if dd == 0:
            return 1
        elif dd == 1:
            return 2
        elif dd == 2:
            return 3
        elif dd == 3:
            return 0


K = int(input())
for i in range(K):
    iy, ix = map(int, input().rstrip().split())
    iy -= 1
    ix -= 1
    arr[iy][ix] = 1

L = int(input())

timer = []
for i in range(L):
    sec, cmd = input().rstrip().split()
    sec = int(sec)
    timer.append([sec, cmd])


while 1:
    time += 1

    yy = y+dir[d][0]
    xx = x+dir[d][1]

    if (yy < 0 or xx < 0 or yy >= N or xx >= N) or arr[yy][xx] == 2:
        break

    elif arr[yy][xx] == 0:
        arr[yy][xx] = 2
        arr[snake[-1][0]][snake[-1][1]] = 0
        snake.pop()
        snake.appendleft([yy, xx])
    elif arr[yy][xx] == 1:
        arr[yy][xx] = 2
        snake.appendleft([yy, xx])

    if idx < len(timer):
        if time == timer[idx][0]:
            if timer[idx][1] == 'L':
                d = find(d, 'L')
            elif timer[idx][1] == 'D':
                d = find(d, 'D')

            idx += 1

    y = yy
    x = xx

print(time)
