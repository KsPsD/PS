import sys
from collections import deque
input = sys.stdin.readline


N, M = map(int, input().split())

dir = [[1, 0], [0, 1], [0, -1], [-1, 0]]

dis = [[0]*M for _ in range(N)]

arr = [[] for _ in range(N)]
ch = [[0]*M for _ in range(N)]
for i in range(N):
    arr[i] = input().rstrip()


q = deque()
q.append((0, 0))

cnt = 0
while q:
    tmp = q.popleft()
    for i in range(4):
        yy = tmp[0] + dir[i][0]
        xx = tmp[1] + dir[i][1]
        if yy < 0 or xx < 0 or yy >= N or xx >= M:
            continue
        if arr[yy][xx] == '1' and ch[yy][xx] == 0:
            ch[yy][xx] = 1
            dis[yy][xx] = dis[tmp[0]][tmp[1]]+1
            q.append((yy, xx))


print(dis[N-1][M-1]+1)
