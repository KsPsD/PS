import sys
import math
input = sys.stdin.readline

M = int(input())
N = int(input())
arr = []
for i in range(M, N+1):
    if i == 1:
        continue
    flag = True

    for j in range(2, int(math.sqrt(i)) + 1):
        if i % j == 0:
            flag = False
            break
    if flag:
        arr.append(i)


if len(arr) > 0:
    print(sum(arr))
    print(min(arr))


else:
    print(-1)
