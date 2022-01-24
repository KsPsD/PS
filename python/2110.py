import sys
input = sys.stdin.readline

ans = -1


def check(length):
    cnt = 1
    prev = arr[0]
    for i in range(1, N):
        if arr[i] - prev >= length:
            cnt += 1
            prev = arr[i]

    return cnt


N, C = map(int, input().rstrip().split())

arr = [int(input()) for i in range(N)]

arr.sort()

lt = 0
rt = arr[-1]-arr[0]

while lt <= rt:
    mid = (lt+rt)//2
    if check(mid) >= C:
        ans = max(ans, mid)
        lt = mid+1
    else:
        rt = mid-1

print(ans)
