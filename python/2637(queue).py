from collections import deque
import sys
input = sys.stdin.readline


N = int(input().rstrip())
M = int(input().rstrip())

arr = [[] for _ in range(N+1)]
ind = [0] * 101  # indegree
v = [[0] * (N+1) for _ in range(N+1)]  # 갯수를 저장할 배열
for i in range(M):
    # cur 만들어야할 부품 prev 사용되는 부품 val 갯수
    cur, prev, val = map(int, input().rstrip().split())
    arr[prev].append((cur, val))  # 만들때 사용하는 부품 기준으로 필요한 부품갯수 저장
    ind[cur] += 1  # 차수 만들어야할 부품

q = deque()

for i in range(1, N+1):
    if ind[i] == 0:  # 차수가 0인 기본 부품에서 시작
        q.append(i)
        v[i][i] = 1  # 기본 부품만 시작값을 1로 할당함


while q:
    here = q.popleft()
    for next in arr[here]:
        for i in range(1, N+1):
            # 다음 부품을 만드는데 필요한 부품 계산, 현재 부품 만드는데 드는 개수에 다음 부품 만들때 필요한 부품 곱해줌
            v[next[0]][i] += next[1]*v[here][i]
            print(v[next[0]][i])
        ind[next[0]] -= 1
        if ind[next[0]] == 0:
            q.append(next[0])


for i in range(1, N+1):
    if v[N][i]:  # 기본 부품 외에 다른건 시작이 0이었기 때문에 세지 않음
        print(f"{i} {v[N][i]}")
