import sys
input = sys.stdin.readline


def check(num):
    sum = 0
    for val in arr:
        if val >= num:
            sum += val-num
        else:
            continue
    return sum


N, M = map(int, input().rstrip().split())

arr = list(map(int, input().rstrip().split()))

arr.sort()
lt = 0
rt = arr[-1]
ans = 0
while lt <= rt:
    mid = (lt+rt)//2

    if check(mid) >= M:
        ans = max(ans, mid)
        lt = mid+1
    else:
        rt = mid-1


print(ans)
