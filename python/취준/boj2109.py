import sys
input = sys.stdin.readline

N = int(input())
arr=[]
#날짜 체크하기 위한 리스트
ch = [0 for  _ in range(10001)] 
for i in range(N):
    p,d = map(int, input().split())
    arr.append([p,d])
res=0
#금액 기준으로 내림차순 정렬
arr.sort(key=lambda x: -x[0]) 


#정렬된 강의를 날짜를 보면서 가능한 날짜에 체크 해줌 
for i in range(len(arr)):
    for j in range(arr[i][1], 0, -1):
        #가능한 날짜를 찾아서 체크함
        if(ch[j] == 0):
            ch[j] =1
            res+=arr[i][0]
            break


print(res)