import sys
from functools import cmp_to_key
input = sys.stdin.readline
MAX = 500000


def cmp(x, y):
    if g[x] != g[y]:
        if g[x+t] > g[y+t]:
            return 1
        elif g[x+t] < g[y+t]:

            return -1
        else:
            return 0
    else:
        if g[x] > g[y]:
            return 1
        elif g[x] < g[y]:
            return -1
        else:
            return 0


def make_SA(S):
    global N, sa, t
    t = 1
    for i in range(N):
        sa[i] = i
        g[i] = ord(S[i]) - ord('a')
    while t <= N:
        g[N] = -1
        sa.sort(key=cmp_to_key(cmp))
        tg[sa[0]] = 0
        for i in range(1, N):
            if cmp(sa[i-1], sa[i]):
                tg[sa[i]] = tg[sa[i-1]]+1
            else:
                tg[sa[i]] = tg[sa[i-1]]

        for i in range(0, N):
            g[i] = tg[i]

        t <<= 1


S = input().rstrip()
t = 0
N = len(S)
sa = [[0]]*(N)
g = [[0]]*MAX
tg = [[0]]*MAX
r = [[0]]*(N)
lcp = [[0]]*N

make_SA(S)

for i in range(len(S)):
    print(sa[i]+1, end=' ')


print()

S += ' '
for i in range(N):
    r[sa[i]] = i


size = 0
for i in range(N):
    k = r[i]
    if k:
        j = sa[k-1]
        while (S[j+size] == S[i+size]):
            size += 1
        lcp[k] = size

        if size:
            size -= 1

for i in range(N):
    if i == 0:
        print('x', end=' ')
    else:
        print(lcp[i], end=' ')
