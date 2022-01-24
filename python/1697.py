from collections import deque

MAX = 100001
N, K = map(int, input().split())
ch = [0] * MAX


def bfs():
    q = deque()
    q.append((N, 0))
    while q:
        tmp = q.popleft()
        if tmp[0] == K:
            print(tmp[1])
            break
        for next in [tmp[0]-1, tmp[0]+1, tmp[0]*2]:
            if 0 <= next < MAX and ch[next] == 0:
                ch[next] = 1
                q.append((next, tmp[1]+1))


bfs()
