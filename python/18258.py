import sys
from collections import deque
input = sys.stdin.readline

N = int(input().rstrip())
q = deque()

for i in range(N):
    in_ = input().rstrip().split()
    if len(in_) > 1:
        cmd = in_[0]
        val = in_[1]
        q.append(int(val))

    else:
        cmd = in_[0]
        if cmd == "pop":
            if len(q) == 0:
                print(-1)
            else:
                front = q.popleft()
                print(front)
        elif cmd == "size":
            print(len(q))
        elif cmd == "empty":
            if len(q) == 0:
                print(1)
            else:
                print(0)
        elif cmd == "front":
            if len(q) == 0:
                print(-1)
            else:
                print(q[0])
        elif cmd == "back":
            if len(q) == 0:
                print(-1)
            else:
                print(q[-1])
