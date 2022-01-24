import sys

input = sys.stdin.readline


K, N = map(int, input().split())

arr = [int(input().rstrip()) for _ in range(K)]
ans = -1


def check(m):
    num = 0

    for ele in arr:
        num += (ele//m)

    if num >= N:
        return True
    else:
        return False


arr.sort()

lt = 1
rt = max(arr)

while(lt <= rt):
    mid = (lt+rt)//2

    if check(mid):
        ans = max(ans, mid)
        lt = mid+1
    else:
        rt = mid-1


print(ans)
