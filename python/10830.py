import sys
sys.setrecursionlimit(10**8)

N, B = map(int, sys.stdin.readline().split())
ch = {}  # dp


def multipleMatrix(a, b):
    ret = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                ret[i][j] += (a[i][k] * b[k][j])
            ret[i][j] %= 1000

    return ret


def go(mtx, n):
    if n == 1:
        return mtx
    if n in ch:
        return ch[n]
    if (n & 1):
        ch[n] = multipleMatrix(mtx, go(mtx, n-1))
        return ch[n]
    ch[n] = multipleMatrix(go(mtx, n//2), go(mtx, n//2))
    return ch[n]


arr = [[0]*N for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, sys.stdin.readline().rstrip().split()))


ans = go(arr, B)

for i in range(N):
    for j in range(N):
        print(ans[i][j] % 1000, end=" ")
    print()
