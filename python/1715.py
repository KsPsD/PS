import sys
import heapq
input = sys.stdin.readline

N = int(input().rstrip())

arr = [int(input().rstrip()) for _ in range(N)]
psum = 0

heap = []

for ele in arr:
    heapq.heappush(heap, ele)

if len(heap) <= 1:
    print(0)
    exit(0)

if len(heap) <= 2:
    for i in range(len(heap)):
        psum += heap[i]


else:
    x = heapq.heappop(heap)
    y = heapq.heappop(heap)
    psum += x+y
    heapq.heappush(heap, x+y)
    while len(heap) >= 2:
        val1 = heapq.heappop(heap)
        val2 = heapq.heappop(heap)
        psum += val1+val2
        heapq.heappush(heap, val1+val2)

print(psum)
