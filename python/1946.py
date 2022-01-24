# 인덱스로 하면 더 빠름 첫번째 값을 인덱스면 어차피 정렬도 되니까
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    M = int(input())
    seq = [0]*(M+1)
    for _ in range(M):
        i, j = map(int, input().split())
        seq[i] = j
    res = 1
    temp = seq[1]
    for j in seq[2:]:
        if j < temp:
            temp = j
            res += 1
    print(res)

# import sys
# input = sys.stdin.readline

# T = int(input())
# for i in range(T):
#     N = int(input())
#     person = []
#     for i in range(N):
#         f, s = map(int, input().split())
#         person.append((f, s))

#     person.sort(key=lambda x: x[0])

#     point = person[0][1]
#     cnt = 1
#     for p in person:
#         if p[1] < point:
#             point = p[1]
#             cnt += 1

#     print(cnt)
