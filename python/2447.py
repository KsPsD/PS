import sys
input = sys.stdin.readline


def recur(y, x, num):
    if (y//num) % 3 == 1 and (x//num) % 3 == 1:
        print(" ", end='')

    else:
        if num//3 == 0:
            print("*", end='')
        else:
            recur(y, x, num//3)


n = int(input())


for i in range(n):
    for j in range(n):
        recur(i, j, n)

    print()
