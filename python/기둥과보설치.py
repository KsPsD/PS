import sys

input = sys.stdin.readline

n = 5
build_frame = [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [
    2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]

arr = [[-1] * (n+1) for _ in range(n+1)]

for frame in build_frame:
    x, y, a, b = frame
    if a == 0:
        if b == 0:
            if arr[x][y+1] != 0 or arr[x][y+1] != 1:
                arr[x][y] = -1
                arr[x][y+1]-1
        else:
            if y == 0 or arr[x][y] == 0 or arr[x][y] == 1:
                arr[x][y] = 0
                arr[x][y+1] = 0
    else:
        if b == 0:
            if arr[x+1][y] != 0 or (arr[x-1][y] != 1 and arr[x+1][y] != 1):
                arr[x][y] = -1
                arr[x+1][y] = -1

        else:
            if arr[x][y] == 0 or (arr[x][y] == 1 and arr[x+1][y] == 1):
                arr[x][y] = 1
                arr[x+1][y] = 1
