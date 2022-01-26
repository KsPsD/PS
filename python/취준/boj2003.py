import sys

input = sys.stdin.readline

N,M = map(int ,input().split())

arr= list(map(int, input().split()))

lt,rt=0,0
cur= arr[lt]
cnt=0
while(lt<N):
    if cur<M and rt != N-1:
        rt+=1
        cur+=arr[rt]
    else:
        if cur==M:
            cnt+=1
        cur-=arr[lt]
        lt+=1


print(cnt)