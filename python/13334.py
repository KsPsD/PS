import sys
import heapq
input = sys.stdin.readline

N = int(input().rstrip())
arr = []
heap = []
maxi = 0
for i in range(N):
    h, o = map(int, input().rstrip().split())
    if h > o:
        arr.append([o, h])
    else:
        arr.append([h, o])


d = int(input())
arr.sort(key=lambda x: (x[1], x[0]))


for i in range(len(arr)):
    rp = arr[i][1]
    lp = arr[i][0]

    if rp-lp <= d:
        heapq.heappush(heap, lp)

    else:
        continue

    while len(heap) != 0:
        tmp = heap[0]
        if rp-tmp <= d:
            break
        else:
            heapq.heappop(heap)

    maxi = max(maxi, len(heap))


print(maxi)
