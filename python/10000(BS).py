import sys
from bisect import *
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

N = int(input())
arr = []

for i in range(N):
    x, r = map(int, input().rstrip().split())
    arr.append((x-r, x+r))

arr.sort(key=lambda x: (x[0], -x[1]))  # 가장 바깥쪽 원 부터 찾으려고 두번째는 내림차순으로
k = 0


def solve(u, v):
    global k
    if arr[u][1] == arr[v][1]:
        k += 1
        return
    pos = bisect_left(arr, (arr[v][1], -2e9))
    if pos == len(arr):
        return
    if arr[pos][0] == arr[v][1]:
        solve(u, pos)


for i in range(N-1):
    if arr[i][0] == arr[i+1][0]:
        solve(i, i+1)


print(N+k+1)
