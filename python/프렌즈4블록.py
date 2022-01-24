def pop_num(b, m, n):
    pop_set = set()
    # search
    for i in range(1, n):
        for j in range(1, m):
            if b[i][j] == b[i-1][j-1] == b[i-1][j] == b[i][j-1] != '_':
                pop_set |= set([(i, j), (i-1, j-1), (i-1, j), (i, j-1)])
    # set_board
    print(pop_set)
    for i, j in pop_set:
        b[i][j] = 0
    for i, row in enumerate(b):
        print(b)
        empty = ['_'] * row.count(0)
        b[i] = empty + [block for block in row if block != 0]
    return len(pop_set)


def solution(m, n, board):
    count = 0
    b = list(map(list, zip(*board)))
    while True:
        pop = pop_num(b, m, n)
        if pop == 0:
            print(count)
            return count
        count += pop


solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"])
