import sys 
input = sys.stdin.readline

n = int(input())
arr= list(map(int, input().split()))
x= int(input())

arr.sort()
# 투포인터를 사용해서  x값을 갖는 순서쌍 개수 찾는다.
lt,rt= 0,n-1
cnt=0
while(lt<rt):
    if arr[lt] + arr[rt] ==x:
        rt-=1
        cnt+=1
    elif arr[lt] + arr[rt] <x:
        lt+=1
    else:
        rt-=1

print(cnt)