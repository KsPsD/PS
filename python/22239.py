import sys
from collections import defaultdict
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N, C = map(int, input().split())
res_list = list(map(int, input().split()))
const = []
dic = defaultdict(set)

# 제약 부분
for i in range(N):
    p_const = list(map(int, input().split()))
    const.append(deque(p_const[1:]))

# 카드 숫자 별로 값 저장
card = {}
for i in range(1, C+1):
    in_ = input().split()[1]
    card[i] = int(in_)

# 카드 값마다 내야하는 사람 번호
for i in range(N):
    for j in const[i]:
        dic[card[j]].add(i)


ans = []


def go(idx):
    if idx == C:
        print(*ans)
        sys.exit()

    # 값이 없다면 그냥 종료
    if res_list[idx] not in dic:
        print(-1)
        sys.exit()

    for player in dic[res_list[idx]]:
        if const[player] and card[const[player][0]] == res_list[idx]:
            tmp = const[player].popleft()  # 현 플레이어의 가장 앞 번호 카드
            ans.append(player+1)

            go(idx+1)

            const[player].appendleft(tmp)

            ans.pop()


# for num in res_list:
#     if num not in dic:
#         print(-1)
#         exit()

go(0)
print(-1)
