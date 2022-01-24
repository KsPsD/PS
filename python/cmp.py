import sys


N = int(sys.stdin.readline().strip())

point_arr = [tuple(map(int, sys.stdin.readline().strip().split()))
             for _ in range(N)]

point_arr.sort(key=lambda x: x[0])


def calc(pos1, pos):
    return pos1[0]


def cal_shortest_distance(arr):
    n = len(arr)

    if n == 2:
        return ((arr[0][0] - arr[1][0]) ** 2 + (arr[0][1] - arr[1][1]) ** 2)

    if n == 3:
        dist1 = (arr[0][0] - arr[1][0]) ** 2 + (arr[0][1] - arr[1][1]) ** 2
        dist2 = (arr[1][0] - arr[2][0]) ** 2 + (arr[1][1] - arr[2][1]) ** 2
        dist3 = (arr[0][0] - arr[2][0]) ** 2 + (arr[0][1] - arr[2][1]) ** 2
        return min(dist1, dist2, dist3)
    pl = 0
    pr = n - 1

    pc = (pl + pr) // 2

    left_dist = cal_shortest_distance(arr[:pc])
    right_dist = cal_shortest_distance(arr[pc:])
    min_dist = min(left_dist, right_dist)

    for i in range(pc, -1, -1):

        for j in range(pc + 1, pr + 1):
            if min_dist <= (arr[j][0] - arr[i][0]) ** 2:
                break

            if min_dist <= (arr[j][1] - arr[i][1]) ** 2:
                continue

            now_dist = (arr[i][0] - arr[j][0]) ** 2 + \
                (arr[i][1] - arr[j][1]) ** 2
            min_dist = min(min_dist, now_dist)

    return min_dist


print(cal_shortest_distance(point_arr))
