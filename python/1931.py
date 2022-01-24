import sys
from collections import defaultdict
input = sys.stdin.readline
scd = list()

N = int(input())

for i in range(N):
    s, e = map(int, input().split())
    scd.append((s, e))


scd.sort(key=lambda x: (x[1], x[0]))

cur_meet = scd[0][1]
cnt = 1
for i in range(1, len(scd)):
    if cur_meet <= scd[i][0]:
        cur_meet = scd[i][1]
        cnt += 1

print(cnt)
