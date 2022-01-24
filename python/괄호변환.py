import sys
input = sys.stdin.readline

p = ")("


def check(sent):
    cnt = 0
    for i in sent:
        if i == '(':
            cnt += 1
        else:
            if(cnt == 0):
                return False
            cnt -= 1

    return True


def go(sent):
    if sent == "":
        return sent
    u, v = "", ""
    cnt_1 = 0
    cnt_2 = 0
    for i in range(len(sent)):
        if sent[i] == '(':
            cnt_1 += 1
        else:
            cnt_2 += 1
        if cnt_1 == cnt_2:
            u = sent[:i+1]
            v = sent[i+1:]
            break
    if check(u):
        return u+go(v)
    else:
        tmp = "("
        tmp += go(v)+")"
        u = u[1:-1]
        for i in u:
            if i == '(':
                tmp += ')'
            else:
                tmp += '('

        return tmp


def solution(sent):
    if(check(sent)):
        return sent
    else:
        return go(sent)


print(solution(p))
