import sys
input = sys.stdin.readline


N = int(input())

st = []
ans = []
cnt = 0
flag = True

for i in range(N):
    val = int(input())
    while cnt < val:
        cnt += 1
        st.append(cnt)
        ans.append('+')
    if st[-1] == val:
        st.pop()
        ans.append('-')
    else:
        flag = False

if not flag:
    print("NO")

else:
    print(*ans, end="\n")
