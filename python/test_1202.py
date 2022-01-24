import sys
import heapq
input = sys.stdin.readline

N, K = map(int, input().split())

j = []
bag = []
heap = []
for i in range(N):
    m, v = map(int, input().split())
    j.append((m, v))

for i in range(K):
    bag.append(int(input()))

j.sort(key=lambda x: (x[0], x[1]))
bag.sort()

idx = 0
res = 0
for i in range(K):
    while idx < N and j[idx][0] <= bag[i]:
        heapq.heappush(heap, -j[idx][1])
        idx += 1
    if heap:
        val = heapq.heappop(heap)
        res += -val


print(res)
