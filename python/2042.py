import sys
input = sys.stdin.readline

tree = []
v = []


def sum(idx):
    res = 0
    while(idx > 0):
        res += tree[idx]
        idx -= (idx & -idx)
    return res


def update(idx, val):
    while(idx < len(tree)):
        tree[idx] += val
        idx += (idx & -idx)


n, m, k = map(int, input().split())

tree = [0 for _ in range(n+1)]
v = [0 for _ in range(n+1)]
for i in range(1, n+1):
    v[i] = int(input())

for i in range(1, n+1):
    update(i, v[i])

for i in range(m+k):
    cmd, a, b = map(int, input().split())

    if cmd == 1:
        diff = b-v[a]
        v[a] = b
        update(a, diff)

    else:
        print(sum(b) - sum(a-1))
