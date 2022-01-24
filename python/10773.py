import sys
input = sys.stdin.readline


K = int(input())

st = []
for i in range(K):
    num = int(input())
    if num == 0:
        st.pop()
    else:
        st.append(num)

if len(st) != 0:
    print(sum(st))
else:
    print(0)
