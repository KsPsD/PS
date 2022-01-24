import sys
from collections import Counter
input = sys.stdin.readline


N = int(input())

arr = list(map(int, input().split()))

st = []

ct = Counter(arr)
st.append(0)

for i in range(1, len(arr)):
    if not st:
        st.append(i)

    while st and ct[arr[st[-1]]] < ct[arr[i]]:
        idx = st.pop()
        arr[idx] = arr[i]

    st.append(i)


while st:
    idx = st.pop()
    arr[idx] = -1

for i in arr:
    print(i)
