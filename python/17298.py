import sys
input = sys.stdin.readline


N = int(input())

arr = list(map(int, input().split()))

st = []
st.append(0)

for i in range(1, len(arr)):
    if not st:
        st.append(i)
    while st and arr[st[-1]] < arr[i]:
        idx = st.pop()
        arr[idx] = arr[i]

    st.append(i)

while st:
    arr[st.pop()] = -1

for e in arr:
    print(e)
