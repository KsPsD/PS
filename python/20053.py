def move(cnt, dy, dx, direction):
    for _ in range(cnt + 1):
        sy, sx = init['sy'] + dy, init['sx'] + dx
        init['sy'], init['sx'] = sy, sx
        if sy < 0 or sx < 0:
            break
        spreads = 0
        for dy, dx, r in rate[direction]:
            ny = sy + dy
            nx = sx + dx
            if r == 0:
                sand = desert[sy][sx] - spreads
            else:
                sand = int(desert[sy][sx] * r)
            if 0 <= nx < N and 0 <= ny < N:
                desert[ny][nx] += sand
            else:
                init['res'] += sand
            spreads += sand


N = int(input())
desert = [list(map(int, input().split())) for _ in range(N)]
init = {'sy': N//2, 'sx': N//2, 'res': 0}
left = [(-2, 0, 0.02), (2, 0, 0.02), (-1, -1, 0.1), (-1, 0, 0.07), (-1, 1, 0.01),
        (1, -1, 0.1), (1, 0, 0.07), (1, 1, 0.01), (0, -2, 0.05), (0, -1, 0)]
right = [(y, -x, z) for y, x, z in left]
down = [(-x, y, z) for y, x, z in left]
up = [(-y, x, z) for y, x, z in down]
rate = {'left': left, 'right': right, 'down': down, 'up': up}

for i in range(N):
    if i % 2 == 0:
        move(i, 0, -1, 'left')
        move(i, 1, 0, 'down')
    else:
        move(i, 0, 1, 'right')
        move(i, -1, 0, 'up')

print(init['res'])
