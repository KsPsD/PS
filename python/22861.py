import sys
from collections import defaultdict

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

direc = defaultdict(lambda: [[], []])
f_num = 0


def go(target):
    if target not in direc:
        return

    for file in direc[target][0]:
        arr.append(file)

    for next_folder in direc[target][1]:
        go(next_folder)


N, M = map(int, input().split())

for i in range(N+M):
    file = list(sys.stdin.readline().split())
    direc[file[0]][int(file[2])].append(file[1])


k = int(input())
for i in range(k):
    From, To = input().rstrip().split()
    parent_From, From = From.split('/')[-2:]
    To = To.split('/')[-1]

    direc[To][1] += direc[From][1]
    for file in direc[From][0]:
        if file not in direc[To][0]:
            direc[To][0].append(file)
    del direc[From]

    direc[parent_From][1].remove(From)


q = int(input())

for i in range(q):
    query = input().rstrip().split('/')
    arr = []
    go(query[-1])

    print(len(set(arr)), len(arr))
