import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

N = int(input())
cnt = [0, 0]
arr = [[0] * N for _ in range(N)]


def check(y, x, size):
    if size == 1:
        True
    for i in range(y, y+size):
        for j in range(x, x+size):
            if arr[y][x] != arr[i][j]:
                return False
    return True


def go(y, x, size):
    if check(y, x, size) == True:
        cnt[arr[y][x]] += 1
        return

    go(y, x, size//2)
    go(y, x+size//2, size//2)
    go(y+size//2, x, size//2)
    go(y+size//2, x+size//2, size//2)


for i in range(N):
    arr[i] = list(map(int, input().rstrip().split()))


go(0, 0, N)


print(cnt[0])
print(cnt[1])
