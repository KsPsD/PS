import sys

chicken = []
home = []
ans = sys.maxsize
ch = []


def go(idx, cnt):
    global ans
    if idx > len(chicken):
        return

    if cnt == M:
        sum = 0
        for i in range(len(home)):
            dis = sys.maxsize
            for j in range(len(chicken)):
                if ch[j] == 1:
                    dis = min(dis, abs(home[i][0] - chicken[j]
                                       [0]) + abs(home[i][1] - chicken[j][1]))
            sum += dis

        ans = min(ans, sum)
        return

    for i in range(idx, len(chicken)):
        ch.append(i)
        go(idx+1, cnt+1)
        ch.pop()


N, M = map(int, input().split())
arr = [[0] * N for _ in range(N)]
for i in range(N):
    arr[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            home.append((i, j))
        elif arr[i][j] == 2:
            chicken.append((i, j))
go(0, 0)

print(ans)
