import sys
input = sys.stdin.readline


N, K = map(int, input().split())

number = input().rstrip()

st = []

for i in number:

    # 스택이 비어 있지 않을때 top 값 보다 크고 바꿀 기회가 있을때
    while len(st) != 0 and st[-1] < int(i) and K > 0:
        qq = st.pop()
        K -= 1

    st.append(int(i))  # 그렇지 않으면 그냥 넣어줌

st = list(map(str, st))
ans = ""
if K != 0:
    for i in range(len(st)-K):
        ans += st[i]
else:
    ans = "".join(st)

print(ans)
