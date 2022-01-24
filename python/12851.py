import sys
from collections import deque
input = sys.stdin.readline

MAX = 100001
N, K = map(int, input().split())
ch = [-1] * MAX
ch[N] = 0
q = deque()
cnt = 0
q.append(N)
while q:
    tmp = q.popleft()

    if tmp == K:
        cnt += 1

    for next in [tmp + 1, tmp-1, tmp * 2]:
        if 0 <= next < MAX:
            if ch[next] == -1 or ch[next] == ch[tmp] + 1:  # 이거 헷갈림 그니까 새로운 값이 시간이 같으면
                # 그 값으로 바꿔줌 결국 최소시간으로 가는 갯수를 세줘야 해서 같아도 업데이트함
                ch[next] = ch[tmp] + 1
                q.append(next)

print(ch[K])
print(cnt)

# input = sys.stdin.readline

# MAX = 100001
# N, K = map(int, input().split())
# ch = [0] * MAX
# ch[N] = 0
# q = deque()
# cnt = 0
# q.append((N, 0))
# mini = 0
# while q:
#     tmp = q.popleft()
#     ch[tmp[0]] = 1
#     if mini != 0 and mini == tmp[1] and tmp[0] == K:
#         cnt += 1
#     if tmp[0] == K and mini == 0:
#         mini = tmp[1]
#         cnt += 1
#     for next in [tmp[0] + 1, tmp[0]-1, tmp[0] * 2]:
#         if 0 <= next < MAX:
#             if ch[next] == 0:
#                 q.append((next, tmp[1]+1))

# print(mini)
# print(cnt)
