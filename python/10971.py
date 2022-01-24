import sys

input = sys.stdin.readline

N = int(input())
arr = []
ch = [[0] for _ in range(N)]
start = 0
mini = 99999999


def dfs(node, level, sum):
    global mini
    if level == N-1:
        if arr[node][start]:
            mini = min(mini, sum+arr[node][start])
            return
    else:
        for i in range(N):
            if ch[i] == 0 and arr[node][i] != 0:
                ch[i] = 1
                dfs(i, level+1, sum + arr[node][i])
                ch[i] = 0


for i in range(N):
    arr.append(list(map(int, input().split())))

print(ch)
for i in range(N):
    start = i
    ch[i] = 1
    dfs(i, 0, 0)
    ch[i] = 0

print(mini)
