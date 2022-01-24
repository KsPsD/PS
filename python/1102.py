import sys

input = sys.stdin.readline

N = int(input())

arr = []
ch = []
dp = [0] * (1 << N)


def count(state):
    cnt = 0
    for i in range(N):
        if state & (1 << i):
            cnt += 1
    return cnt


def go(state):
    if count(state) >= P:
        return 0
    if dp[state] != 0:
        return dp[state]
    dp[state] = sys.maxsize
    for cur in range(N):

        if state & (1 << cur) != 1:
            continue

        for next in arr[cur]:
            if next != 0 and state & (1 << next) == 0:
                dp[state] = min(
                    dp[state], go(state | (1 << next)) + arr[cur][next])

    return dp[state]


for i in range(N):
    arr.append(list(map(int, input().split())))

in_ = input().rstrip()
state = 0
for i in range(len(in_)):
    if in_[i] == 'Y':
        state | (1 << i)

P = int(input())

print(go(state))
