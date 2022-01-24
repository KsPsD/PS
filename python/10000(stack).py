import sys
input = sys.stdin.readline


N = int(input())
arr = []
K = 0
st = []

for i in range(N):
    x, r = map(int, input().rstrip().split())
    arr.append((1, x-r))  # 왼쪽
    arr.append((-1, x+r))  # 오른쪽


arr.sort(key=lambda x: (x[1], x[0]))

ans = 1

for cur in arr:
    if cur[0] == -1:
        acc_width = 0
        while st:
            top = st.pop()

            if top[0] == 1:
                width = cur[1] - top[1]

                if width == acc_width:
                    ans += 2

                else:
                    ans += 1

                st.append((0, width))
                break

            elif top[0] == 0:
                acc_width += int(top[1])

    st.append(cur)

print(ans)
