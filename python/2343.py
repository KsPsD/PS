import sys
input = sys.stdin.readline

N, M = map(int, input().split())

arr = list(map(int, input().split()))
# print(arr)


def check(size):
    cnt = 1
    cur = 0
    for i in arr:
        if cur+i > size:
            cnt += 1
            if i <= size:
                cur = i
            else:
                return False
        else:
            cur += i

    if cnt <= M:

        return True
    else:
        return False


lt = max(arr)
rt = sum(arr)
mini = sys.maxsize
while(lt <= rt):
    mid = (lt+rt)//2
    if(check(mid) == False):
        lt = mid+1

    else:
        # mini = mid

        rt = mid-1


print(lt)
