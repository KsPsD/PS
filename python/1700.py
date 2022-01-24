import sys
from collections import deque
input = sys.stdin.readline
N, K = map(int, input().split())

arr = list(map(int, input().split()))
hole = []
ans = 0
for cur in range(K):
    if arr[cur] in hole:
        continue

    if len(hole) is not N:
        hole.append(arr[cur])

    else:
        ch_idx = 0
        prev = -1
        for c_hole in hole:
            cnt = 0
            for i in range(cur+1, K):
                if arr[i] == c_hole:
                    break
                cnt += 1

            if cnt > prev:
                prev = cnt
                ch_idx = hole.index(c_hole)

        ans += 1
        hole[ch_idx] = arr[cur]

print(ans)
