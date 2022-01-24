import sys
input = sys.stdin.readline

N = int(input())

arr = [int(input().rstrip()) for _ in range(N)]

st = []


for i in range(len(arr)):
    while len(st) != 0:
        if st[-1] > arr[i]:
            break

        st.pop()

    st.append(arr[i])


print(len(st))
