import sys
import heapq
input = sys.stdin.readline

heap = []

N = int(input().rstrip())

for i in range(N):
    in_ = int(input().rstrip())
    if(len(heap) != 0 and in_ == 0):
        val = heapq.heappop(heap)
        print(-val)
        continue
    elif len(heap) == 0 and in_ == 0:
        print(0)
        continue
    else:
        heapq.heappush(heap, -in_)
