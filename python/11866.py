import sys
from collections import deque
input = sys.stdin.readline


N, K = map(int, input().split())
q = deque()
ans = []
for i in range(1, N+1):
    q.append(i)
pt = 0
while len(q) != 0:
    pt += 1
    if pt == K:
        ans.append(q.popleft())
        pt = 0
        continue
    val = q[0]
    q.popleft()
    q.append(val)


print("<", end="")
for i in range(len(ans)-1):
    print(f"{ans[i]}, ", end="")

print(f"{ans[-1]}>")
