import sys

input = sys.stdin.readline

N = int(input())
sent = input().rstrip()
cnt = 0
for idx in range(0, N-1):
    if sent[idx] == 'E' and sent[idx+1] != 'E':
        cnt += 1
print(cnt)
