import sys
import heapq
input = sys.stdin.readline

N = int(input().rstrip())


arr = [int(input().rstrip()) for _ in range(N)]

max_heap = []
min_heap = []

for ele in arr:
    if len(max_heap) > len(min_heap):
        heapq.heappush(min_heap, ele)
    else:
        heapq.heappush(max_heap, -ele)

    if len(max_heap) != 0 and len(min_heap) != 0:
        if -max_heap[0] > min_heap[0]:
            max_val = heapq.heappop(max_heap)
            min_val = heapq.heappop(min_heap)

            heapq.heappush(max_heap, -min_val)
            heapq.heappush(min_heap, -max_val)

    print(-max_heap[0])
