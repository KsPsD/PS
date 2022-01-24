import sys
input = sys.stdin.readline


str = input().rstrip()
st = []
cnt = 0
ans = 0
for i in range(len(str)):
    if str[i] == ')':
        # 레이저일 경우
        if st[-1]+1 == i:
            st.pop()
            cnt += len(st)
        # 아니면 그냥 개수 1개
        else:
            st.pop()
            cnt += 1
    else:
        st.append(i)

print(cnt)
