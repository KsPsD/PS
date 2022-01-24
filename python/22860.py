import sys
sys.setrecursionlimit(10**8)

input = sys.stdin.readline

direc = {}
# dp = {}
f_num = 0


def go(target, kinds):
    global f_num
    if target not in direc:
        return

    for title, val in direc[target]:
        if val == 0:
            if title not in kinds:
                kinds.add(title)
            f_num += 1

        else:
            go(title, kinds)

    return


N, M = map(int, input().split())

for i in range(N+M):
    From, To, Id = input().rstrip().split()
    if From not in direc:
        direc[From] = []
        direc[From].append([To, int(Id)])
    else:
        direc[From].append([To, int(Id)])


q = int(input())

for i in range(q):
    query = input().rstrip().split('/')
    SET = set()
    f_num = 0
    go(query[-1], SET)

    print(len(SET), f_num)
