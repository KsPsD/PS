# 못품


def attach(x, y, M, key, board):
    for i in range(M):  # 키를 넣는거 현재 위치에서 키만큼 다 본다
        for j in range(M):
            board[x+i][y+j] += key[i][j]


def detach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] -= key[i][j]


def rotate90(arr):  # 돌리는거 다르게 구현도 해보자
    return list(zip(*arr[::-1]))


def rotate(arr):
    r_n = len(arr)
    ret = [[0] * r_n for _ in range(r_n)]

    for r in range(r_n):
        for c in range(r_n):
            ret[c][r_n-1-r] = arr[r][c]

    return ret


def check(board, M, N):
    for i in range(N):
        for j in range(N):
            if board[M+i][M+j] != 1:
                return False
    return True


def solution(key, lock):
    M, N = len(key), len(lock)

    board = [[0] * (M*2 + N) for _ in range(M*2 + N)]  # 자물쇠 크기에다가 키*2 크기만큼 만듬
    # 자물쇠 중앙 배치
    for i in range(N):
        for j in range(N):
            board[M+i][M+j] = lock[i][j]  # 중앙에 자물쇠가 와야 하니 키크기m 만큼 더해서 구해줌

    rotated_key = key
    # 모든 방향 (4번 루프)
    for _ in range(4):
        rotated_key = rotate90(rotated_key)
        for x in range(1, M+N):  # 키 크기 + 자물쇠 왜냐면 뒤에서 넘어가는 건 신경 안써도됨
            for y in range(1, M+N):
                # 열쇠 넣어보기
                attach(x, y, M, rotated_key, board)
                # lock 가능 check
                if(check(board, M, N)):
                    return True
                # 열쇠 빼기
                detach(x, y, M, rotated_key, board)

    return False
