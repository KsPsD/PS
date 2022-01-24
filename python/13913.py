from collections import deque
import sys

sys.setrecursionlimit(10**8)

input = sys.stdin.readline


N, K = map(int, input().split())
MAX = 100001
ch = [0] * MAX
trace = [0] * MAX
q = deque()
q.append((N, 0))
ch[N] = 1


def find_way(start):
    if start == N:
        print(start, end=" ")
        return

    find_way(trace[start])
    print(start, end=" ")


while q:
    tmp = q.popleft()

    if tmp[0] == K:
        print(tmp[1])
        break

    for next in [tmp[0]*2, tmp[0]+1, tmp[0]-1]:
        if 0 <= next < MAX and ch[next] == 0:
            ch[next] = 1
            q.append((next, tmp[1]+1))
            trace[next] = tmp[0]


find_way(K)
