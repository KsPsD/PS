import sys
import heapq
input = sys.stdin.readline

N = int(input())
pq=[] #우선순위 큐를 위한 리스트
arr=[]
ch = [0 for  _ in range(10001)]
for i in range(N):
    p,d = map(int, input().split())
    arr.append([p,d])
res=0
#금액 기준으로 내림차순 정렬
arr.sort(key=lambda x: -x[0]) 

#우선순위 큐에 강의비를 기준으로 정렬하게 함
# for e in arr:
#     heapq.heappush(pq, e[0])
#     #현재 순회하는 값의 날짜보다 pq길이가 더 크면 날짜가 
#     if(len(pq) >  e[1]):
#         heapq.heappop(pq)

#정렬된 강의를 날짜를 보면서 가능한 날짜에 체크 해줌 
for i in range(len(arr)):
    for j in range(arr[i][1], 0, -1):
        #가능한 날짜를 찾아서 체크함
        if(ch[j] == 0):
            ch[j] =1
            res+=arr[i][0]
            break


print(res)