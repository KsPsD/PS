import sys
from bisect import *
import heapq
import math
input = sys.stdin.readline

N = int(input())
arr = []
s = set()


def dist(a, b):
    return (a[0]-b[0]) * (a[0]-b[0]) + (a[1] - b[1]) * (a[1]-b[1])


for i in range(N):
    x, y = map(int, input().rstrip().split())
    arr.append((x, y))

arr = list(set(arr))

arr.sort()

s.add((arr[0][1], arr[0][0]))
s.add((arr[1][1], arr[1][0]))


pos = 0
ans = dist(arr[0], arr[1])


for i in range(2, N):
    while pos < i:
        if ((arr[i][0] - arr[pos][0]) * (arr[i][0]-arr[pos][0]) <= ans):
            break

        s.remove((arr[pos][1], arr[pos][0]))
        pos += 1

    left = bisect_left(list(s), ((arr[i][1] - math.sqrt(ans)), -10001))
    right = bisect_right(list(s), ((arr[i][1] + math.sqrt(ans)), 10001))

    for idx in range(left, right):
        ans = min(ans, dist(arr[idx], arr[i]))
    s.add((arr[i][1], arr[i][0]))


if N != len(arr):
    print(0)
else:
    print(ans)
