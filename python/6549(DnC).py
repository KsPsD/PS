import sys
input = sys.stdin.readline
arr = []


def solve(lt, rt):
    global arr
    if lt == rt:
        return arr[lt]
    mid = (lt+rt)//2
    res = max(solve(lt, mid), solve(mid+1, rt))
    lo = mid
    hi = mid+1
    height = min(arr[lo], arr[hi])
    res = max(res, 2*height)

    while lt < lo or hi < rt:
        if hi < rt and (lt == lo or arr[lo-1] < arr[hi+1]):
            hi += 1
            height = min(height, arr[hi])
        else:
            lo -= 1
            height = min(height, arr[lo])

        res = max(res, height*(hi-lo+1))

    return res


while True:
    input_arr = list(map(int, input().rstrip().split()))
    if input_arr[0] == 0:
        break
    N = input_arr[0]
    arr = input_arr[1:]
    print(solve(0, N-1))
