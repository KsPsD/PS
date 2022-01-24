import sys
input = sys.stdin.readline


arr = []

while 1:
    f_arr = list(map(int, input().rstrip().split()))
    if f_arr[0] == 0:
        break
    ans = 0
    st = []
    arr = f_arr[1:]

    for val in arr:
        tmp = 0
        while len(st) != 0 and st[-1][0] > val:
            tmp += st[-1][1]  # 스택이 갖고 있던 밑변 값을 넘겨준다
            ans = max(ans, tmp * st[-1][0])
            st.pop()

        tmp += 1
        st.append([val, tmp])  # 높이와 밑변

    tmp = 0
    while len(st) != 0:  # 남은 값들 처리
        tmp += st[-1][1]
        ans = max(ans, tmp*st[-1][0])
        st.pop()

    print(ans)
