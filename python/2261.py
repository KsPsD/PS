import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N = int(input())

pos = []
for _ in range(N):
    pos.append(tuple(map(int, input().rstrip().split())))

pos = list(set(pos))
pos.sort(key=lambda x: x[0])


def calc(pos1, pos2):
    return (pos1[0] - pos2[0])**2 + (pos1[1]-pos2[1])**2


def go(points):
    if len(points) == 2:
        return calc(points[0], points[1])
    elif len(points) == 3:
        return min(calc(points[0], points[1]), calc(points[1], points[2]), calc(points[0], points[2]))

    else:
        mid = len(points)//2
        res = min(go(points[:mid]), go(points[mid:]))

        tmp = []
        for i in range(len(points)):
            if (points[i][0] - points[mid][0]) ** 2 <= res:
                tmp.append(points[i])
        if len(tmp) >= 2:
            tmp.sort(key=lambda x: x[1])
            for i in range(len(tmp)-1):
                for j in range(i+1, len(tmp)):
                    if (tmp[i][1] - tmp[j][1])**2 > res:
                        break
                    elif tmp[i][0] < points[mid][0] and tmp[j][0] < points[mid][0]:
                        continue
                    elif tmp[i][0] >= points[mid][0] and tmp[j][0] >= points[mid][0]:
                        continue
                    res = min(res, calc(tmp[i], tmp[j]))
        return res


# 중복된점 계산
if N != len(pos):
    print(0)
else:

    print(go(pos))
