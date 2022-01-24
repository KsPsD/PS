from types import SimpleNamespace
from dataclasses import dataclass, field
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
arr, home, chicken, v = [], [], [], []
# for _ in range(N):
#     arr.append(list(input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]
ans = 1e9


def solve(idx, cnt):
    global ans
    if idx > len(chicken):
        return
    if cnt == M:
        s = 0
        for hx, hy in home:
            d = 1e9
            for j in v:
                cx, cy = chicken[j]
                d = min(d, abs(hx-cx)+abs(hy-cy))
            s += d
        ans = min(ans, s)
        return
    v.append(idx)
    solve(idx+1, cnt+1)
    v.pop()
    solve(idx+1, cnt)


for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            home.append((i+1, j+1))
        elif arr[i][j] == 2:
            chicken.append((i+1, j+1))


solve(0, 0)

print(ans)
