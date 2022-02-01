import sys
from collections import deque
input = sys.stdin.readline

n , l = map(int, input().split())
dq = deque()
arr= list(map(int, input().split()))

for i in range(n):
    while dq and dq[0][0] <= i-l:
        dq.popleft()
    while dq and dq[-1][1] >=arr[i]:
        dq.pop()
    dq.append([i,arr[i]])
    print(dq[0][1])