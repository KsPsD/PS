import sys
from collections import deque
input = sys.stdin.readline


A, B = map(int, input().split())
ch = [0] * 10**9


def bfs(num):
    q = deque()

    res = 0
    q.append((num, 1))
    while q:
        tmp = q.pop()
        if tmp[0] == B:
            res = tmp[1]
            break

        if tmp[0] * 2 <= B:
            q.append((tmp[0] * 2, tmp[1]+1))
        if int(str(tmp[0])+'1') <= B:
            q.append((int(str(tmp[0])+'1'), tmp[1]+1))
    return res


ans = bfs(A)
if ans == 0:
    print(-1)
else:
    print(ans)
