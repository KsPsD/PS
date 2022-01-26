import sys
from collections import deque

input = sys.stdin.readline

N, D, K, C = map(int, input().split())
numbers = [int(input()) for _ in range(N)]
numbers += numbers[:K-1] #뒤에 더 추가해줌 k개 더가도 돼서
counter = [ 0 for _ in range(D+1) ]

dq=deque()
count=0
answer=0


for k, v in enumerate(numbers):
    dq.append(v)
    counter[v]+=1
    if counter[v] ==1:
        count+=1

    if k< K-1:
        continue
    if counter[C] ==0:
        answer = max(answer,count+1)
    else:
        answer = max(answer, count)


    p= dq.popleft()
    counter[p]-=1
    if counter[p] ==0:
        count -=1

print(answer)


import sys
input = sys.stdin.readline

def initResult():
    res = 0

    for num in nums[:k]:
        if cache[num]  == 0:
            res += 1
        cache[num] += 1

    return res


# def slide():
#     ans = initResult()
#     cnt = ans
    
#     for i in range(0,n):
#         if ans <= cnt:
#             ans = cnt if cache[c] else cnt+1

#         left = nums[i]
#         right = nums[(i+k) % n]

#         cache[left] -= 1

#         if cache[left] == 0: cnt -= 1
#         if cache[right] == 0: cnt += 1

#         cache[right] += 1

#     return ans

# nums = []
# n, d, k, c = map(int, input().split())
# for _ in range(n):
#     nums.append(int(input()))

# cache = [0]*(d+1)

# print(slide())