import sys
input = sys.stdin.readline


N = int(input().rstrip())
arr = [[0] * N for _ in range(N)]


def check(y, x, size):  # 일치하는지 확인
    if size == 1:  # 1이면 무조건
        return True
    for i in range(y, y+size):
        for j in range(x, x+size):
            if arr[y][x] != arr[i][j]:
                return False

    return True


def go(y, x, size):
    if check(y, x, size):
        print(arr[y][x], end="")
        return

    print("(", end="")
    go(y, x, size//2)
    go(y, x+size//2, size//2)
    go(y+size//2, x, size//2)
    go(y+size//2, x+size//2, size//2)
    print(")", end="")
    return


for i in range(N):
    arr[i] = input().rstrip()

go(0, 0, N)
