import sys
from collections import deque

input = sys.stdin.readline

# q = deque()
# MAX = 1001
# S = int(input())
# q.append((1, 0, 0))  # 화면개수, 클립보드, 시간
# ch = [[0]*MAX for _ in range(MAX)]
# while q:
#     tmp = q.popleft()

#     if tmp[0] == S:  # 목적 개수 달성하면 출력
#         print(tmp[2])
#         break

#     if ch[tmp[0]][tmp[0]] == 0:  # 클립보드에 개수 복사
#         ch[tmp[0]][tmp[0]] = 1
#         q.append((tmp[0], tmp[0], tmp[2]+1))

#     if tmp[1]+tmp[0] < MAX and ch[tmp[0]+tmp[1]][tmp[1]] == 0:  # 화면에 클립보드에 있는 개수 붙여넣기
#         ch[tmp[0]+tmp[1]][tmp[1]] = 1
#         q.append((tmp[0]+tmp[1], tmp[1], tmp[2]+1))

#     if tmp[0]-1 > 0:  # 화면 이모티콘 개수 하나 빼기
#         if tmp[0] < MAX and ch[tmp[0]-1][tmp[1]] == 0:
#             ch[tmp[0]-1][tmp[1]] = 1
#             q.append((tmp[0]-1, tmp[1], tmp[2]+1))

MAX = 1001
q = deque()
S = int(input())
ch = [[0] * MAX for _ in range(MAX)]
q.append([1, 0, 0])
while q:
    tmp = q.popleft()
    if tmp[0] == S:
        print(tmp[2])
        break

    if ch[tmp[0]][tmp[0]] == 0:
        ch[tmp[0]][tmp[0]] = 1
        q.append([tmp[0], tmp[0], tmp[2]+1])

    if tmp[1]+tmp[0] < MAX and ch[tmp[1]+tmp[0]][tmp[1]] == 0:
        ch[tmp[1]+tmp[0]][tmp[1]] = 1
        q.append([tmp[1]+tmp[0], tmp[1], tmp[2]+1])
    if tmp[0]-1 > 0:
        if tmp[0] < MAX and ch[tmp[0]-1][tmp[1]] == 0:
            ch[tmp[0]-1][tmp[1]] = 1
            q.append([tmp[0]-1, tmp[1], tmp[2]+1])
