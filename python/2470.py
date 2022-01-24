import sys
input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().rstrip().split()))

arr.sort()

# lt = 0
# rt = len(arr)-1
# sum = 0
mini = sys.maxsize
# ans = [0]*2
# while(lt < rt):
#     sum = arr[lt]+arr[rt]
#     if mini > abs(sum):
#         mini = abs(sum)
#         ans[0] = lt
#         ans[1] = rt
#         if sum == 0:
#             break

#     if sum < 0:
#         lt += 1
#     else:
#         rt -= 1


# print(arr[ans[0]], arr[ans[1]])
# 훨씬 느림 이분탐색 , 투포인터가 더빠름
if N == 2:
    print(arr[0], arr[1])

for i in range(N-1):
    start = i+1
    end = N-1
    while start <= end:
        mid = (start+end)//2
        sum = arr[i] + arr[mid]
        if abs(sum) < mini:
            x1, x2, mini = i, mid, abs(sum)

        if sum < 0:
            start = mid + 1
        else:
            end = mid - 1

print(arr[x1], arr[x2])
