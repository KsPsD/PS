import sys
from collections import deque
input= sys.stdin.readline

N,M = map(int,input().split())

arr= [list(input().rstrip()) for _ in range(N)]
ch=[[0]* M for _ in range(N)] #방문한곳 체크하기 위한 배열
#방향
dy=[0,1,0,-1]
dx=[1,0,-1,0]

q=deque()
q.append([0,0,1]) #위치 와 거리
#bfs를 통해 최단거리를 구함
while q:
    tmp = q.popleft()
    y=tmp[0]
    x=tmp[1]
    dist =tmp[2]
    if y== N-1 and x==M-1:
        print(dist)
        break
    for i in range(4):
        yy= y+dy[i]
        xx= x+dx[i]
        if 0<=yy<N and 0<=xx<M:
            if arr[yy][xx] =="1" and ch[yy][xx]==0:
                ch[yy][xx]=1
                q.append([yy,xx,dist+1])



