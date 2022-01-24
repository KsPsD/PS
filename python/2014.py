import sys
import heapq
input = sys.stdin.readline
MAX = 2 << 31

K, N = map(int, input().split())

arr = list(map(int, input().split()))
heap = []

for i in arr:
    heapq.heappush(heap, i)


while N > 0:
    cur = heapq.heappop(heap)
    print(cur)
    for ele in arr:
        if ele * cur >= MAX:
            break
        heapq.heappush(ele*cur)
        if (cur % ele) == 0:
            break
    N -= 1

print(cur)
