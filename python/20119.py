import sys
from dataclasses import dataclass, field
from collections import deque
from typing import List

# 물약 데이터 클래스
@dataclass
class Potion:
    number: int = None
    connect: List[int] = field(default_factory=list)
    recipe: List[int] = field(default_factory=list)
    indegree: List[int] = field(default_factory=list)
    flag: bool = False


input = sys.stdin.readline

N, M = map(int, input().split())
res = []
potion_list = [Potion() for _ in range(0, N+1)]


for i in range(M):
    k, *x, r = map(int, input().split())
    for j in x:
        potion_list[j].connect.append(r)
# 포션 레시피 들을 추가해주고 그에 맞게 진입 차수도 저장해 줍니다.
    potion_list[r].recipe.append(x)
    potion_list[r].indegree.append(len(x))


L = int(input())

# 기존에 가지고 있는 포션 처리
in_ = map(int, input().split())
for ele in in_:
    potion_list[ele].flag = True
    potion_list[ele].number = ele
    res.append(ele)

q = deque()

for i in res:
    q.append(potion_list[i])

while q:
    tmp = q.popleft()
    cur_number = tmp.number
    # 현재 포션과 연결된 포션들을 탐색합니다
    for i in tmp.connect:
        next = i
        if potion_list[next].flag == True:
            continue
        for j in range(len(potion_list[next].recipe)):
            if potion_list[next].flag:
                break
            for k in range(len(potion_list[next].recipe[j])):
                # 탐색하는 레시피에 가지고 있는 포션이 있다면 레시피의 차수를 줄여줍니다.
                if cur_number == potion_list[next].recipe[j][k]:
                    potion_list[next].recipe[j][k] = -1
                    potion_list[next].indegree[j] -= 1
                    # 레시피의 포션들이 다 존재 한다면 포션을 체크해 줍니다.
                    if potion_list[next].indegree[j] == 0:
                        potion_list[next].flag = True
                        break

        if potion_list[next].flag:
            res.append(next)
            potion_list[next].number = next
            q.append(potion_list[next])


res.sort()
print(len(res))
print(*res, end=" ")
