import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())

MAX = 100001
q = deque()
q.append((N, 0))
ch = [0]*MAX
while q:
    tmp = q.popleft()
    if tmp[0] == K:
        print(tmp[1])
        break
    for next in [tmp[0]-1, tmp[0]+1, tmp[0]*2]:
        if 0 <= next < MAX:
            if ch[next] == 0:
                q.append((next, tmp[1]+1))
                ch[next] = 1
