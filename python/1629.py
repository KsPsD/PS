import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)


def go(A, B):
    if B == 0:
        return 1

    tmp = go(A, B//2)
    if B % 2 == 0:
        return (tmp * tmp) % C

    else:
        return ((tmp * tmp) * A) % C


A, B, C = map(int, input().rstrip().split())


print(go(A, B) % C)
