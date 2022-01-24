from collections import defaultdict
import sys
input = sys.stdin.readline
N, M = map(int, input().split())

d = []
b = []

for i in range(N):
    d.append(input().rstrip())
for i in range(M):
    b.append(input().rstrip())
d = set(d)
b = set(b)

ans = d & b
ans = sorted(ans)
print(len(ans))
print(*ans, sep="\n")
