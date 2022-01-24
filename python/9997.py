from itertools import combinations
import sys
input = sys.stdin.readline

cmp = 0
ans = 0
ch = [0]*26


n = int(input())


def find(level, sum):
    global ans
    if level == n-1:
        if sum == cmp:
            ans += 1
        return

    if level < n-1:
        find(level+1, sum | ch[level+1])
        find(level+1, sum)


for i in range(26):
    cmp |= (1 << i)

for i in range(n):
    word = input().rstrip()
    for j in range(len(word)):
        ch[i] |= (1 << (ord(word[j]) - ord('a')))


find(-1, 0)

print(ans)
