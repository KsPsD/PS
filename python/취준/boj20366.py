import sys
input = sys.stdin.readline
N=int(input())
arr=list(map(int, input().split()))

arr.sort()

ans  = sys.maxsize

for i in range(N-3):
    for j in range(i+3, N):
        lt = i+1
        rt = j-1

        while(lt<rt):
            a = arr[i] + arr[j]
            e = arr[lt] + arr[rt] 
            res =e -a
            ans = min(ans, abs(res))


            if res > 0:
                rt =rt -1
            else:
                lt =lt+1


print(ans)