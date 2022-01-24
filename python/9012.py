import sys
input = sys.stdin.readline


N = int(input())

for i in range(N):
    flag = True
    st = []
    sent = input().rstrip()
    for ele in sent:
        if ele == "(":
            st.append(ele)
        elif ele == ")":
            if len(st) == 0:
                flag = False
                break
            st.pop()
    if len(st) == 0 and flag is not False:
        flag = True
    elif len(st) != 0:
        flag = False

    if flag:
        print("YES")
    else:
        print("NO")
