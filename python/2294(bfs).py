import sys
from collections import deque


def main():
    n, k = map(int, sys.stdin.readline().split())
    coins = set(int(sys.stdin.readline()) for _ in range(n))
    check = [0] * (k + 1)  # 중요!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ans = -1
    q = deque()
    for c in coins:
        if c == k:
            ans = 1
            break
        elif c < k:
            q.append((c, 1))
            check[c] = 1
    result = 10001
    if ans == -1:
        while q:
            coin, cnt = q.popleft()
            if coin == k:
                result = cnt
                break
            for c in coins:
                if coin + c <= k and check[coin + c] == 0:
                    check[coin + c] = 1
                    q.append((coin + c, cnt + 1))
    if result != 10001:
        ans = result
    print(ans)


main()
