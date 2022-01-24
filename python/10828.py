import sys
input = sys.stdin.readline


N = int(input())
st = []
for i in range(N):
    in_ = input().rstrip().split()
    if len(in_) > 1:
        cmd = in_[0]
        val = int(in_[1])
        if cmd == "push":
            st.append(val)
    else:
        cmd = in_[0]
        if cmd == "top":
            if len(st) != 0:
                print(st[-1])
            else:
                print(-1)
        elif cmd == "pop":
            if len(st) != 0:
                v = st.pop()
                print(v)
            else:
                print(-1)

        elif cmd == "size":
            print(len(st))
        elif cmd == "empty":
            if len(st) == 0:
                print(1)
            else:
                print(0)
