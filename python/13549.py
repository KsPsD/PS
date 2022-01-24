from collections import deque
import sys
input = sys.stdin.readline


N, K = map(int, input().split())

MAX = 100001
ch = [0] * MAX
q = deque()
q.append((N, 0))

while q:
    tmp = q.popleft()
    if tmp[0] == K:
        print(tmp[1])
        break
    for next in [tmp[0]-1, tmp[0]+1, 2*tmp[0]]:
        if 0 <= next < MAX and ch[next] == 0:
            ch[next] = 1
            if next == tmp[0]-1 or next == tmp[0]+1:  # x+1,x-1 로 한칸 가는 경우
                q.append((next, tmp[1]+1))
            if next == tmp[0]*2:  # 2*x 만큼 가는경우
                q.appendleft((next, tmp[1]))  # 데크의 앞에 넣어준다
