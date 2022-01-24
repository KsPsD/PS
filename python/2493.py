import sys
input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().rstrip().split()))
st = []
for i in range(len(arr)):
    flag = False
    while len(st) != 0:
        if st[-1][1] > arr[i]:
            print(st[-1][0]+1)
            st.append([i, arr[i]])
            flag = True
            break

        st.pop()

    if len(st) == 0:
        print(0)
    if flag == False:
        st.append([i, arr[i]])

    print(st)
