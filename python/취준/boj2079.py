import sys

input= sys.stdin.readline

dp = [[False] * 2501 for _ in range(2501)]
res= [0 for _ in range(2501)]
s=  input().strip()
s= " "+s
size= len(s)
def paline():
    global s
    for i in range(2,size-1):
        for j in range(1, size-i):
            if s[j] == s[j+i] and dp[j+1][j+i-1]:
                dp[j][j+i] = dp[j+i][j] =True


for i in range(1,size+1):
    dp[i][i] =True


for  i in range(1, size-1):
    if(s[i] == s[i+1]):
        dp[i][i+1]= True
        dp[i+1][i] = True


paline()

for i in range(1,size):
    for j in range(1,i+1):
        if dp[i][j] :
            if res[i] ==0 or res[i] > res[j-1] +1:
                res[i] = res[j-1] +1
print(res[len(s) -1])