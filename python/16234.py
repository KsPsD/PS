import sys
from collections import deque


def bfs(i, j, visited, ans):
    q = deque()
    union = [(i, j)]
    q.appendleft((i, j))
    visited[i][j] = ans
    cnt = 1
    population = country[i][j]

    while q:
        x, y = q.pop()

        for d in dir:
            nx, ny = x+d[0], y+d[1]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] != ans and L <= abs(country[nx][ny] - country[x][y]) <= R:
                    visited[nx][ny] = ans
                    q.appendleft((nx, ny))
                    union.append((nx, ny))
                    cnt += 1
                    population += country[nx][ny]

    # 인구 이동
    if cnt > 1:
        pop_mean = population//cnt
        for x, y in union:
            country[x][y] = pop_mean
            search.appendleft((x, y))
        return True
    return False


N, L, R = map(int, sys.stdin.readline().split())
dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
country = []
for _ in range(N):
    country.append(list(map(int, sys.stdin.readline().split())))

search = deque()
for i in range(N):
    for j in range(N):
        search.appendleft((i, j))

visited = [[-1]*N for _ in range(N)]


def solution():
    ans = 0
    while True:
        stop = True
        for _ in range(len(search)):
            i, j = search.pop()
            if visited[i][j] != ans:
                if bfs(i, j, visited, ans):
                    stop = False
        if stop:
            break
        ans += 1
    print(ans)


solution()
