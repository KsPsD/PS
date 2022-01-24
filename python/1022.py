import sys

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

r1, c1, r2, c2 = map(int, input().split())

board = [[0] * (c2-c1+1) for _ in range(r2-r1+1)]
number_of_board = (c2-c1+1) * (r2-r1+1)

y = x = 0
num = 1
cnt = 0
dcnt = 1
d = 0

while number_of_board > 0:
    if r1 <= y <= r2 and c1 <= x <= c2:
        number_of_board -= 1
        board[y - r1][x - c1] = num
        max_num = num
    num += 1
    cnt += 1

    y = y + dy[d]
    x = x + dx[d]

    if cnt == dcnt:
        cnt = 0
        d = (d+3) % 4
        if d == 0 or d == 2:
            dcnt += 1


max_num_len = len(str(max_num-1))
for i in range(r2-r1+1):
    for j in range(c2-c1+1):
        print(str(board[i][j]).rjust(max_num_len), end=' ')
    print()
