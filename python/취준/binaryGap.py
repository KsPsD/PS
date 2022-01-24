def solution(N):
    pos = 0
    cnt = 0
    flag = False
    ans = 0
    while N//2 != 0:
        if N % 2 == 1:
            ans = max(cnt, ans)
            cnt = 0
            flag = True
        elif flag and N % 2 == 0:
            cnt += 1
        N = N//2

    if flag:
        ans = max(cnt, ans)

    return ans
