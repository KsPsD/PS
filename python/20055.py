from collections import deque
import sys
input = sys.stdin.readline


n, k = map(int, input().split())
belt = deque(list(map(int, input().split())))
robot = deque([0]*n)
res = 0

while 1:
    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0 #벨트를 돌리고 로봇마지막칸에 애 내려줌
    if sum(robot):
        for i in range(n-2, -1, -1): #마지막칸은 나중에 처리
            if robot[i] == 1 and robot[i+1] == 0 and belt[i+1] >= 1:
                robot[i+1] = 1
                robot[i] = 0
                belt[i+1] -= 1
        robot[-1] = 0 #여기서 마지막애 내려줌
    if robot[0] == 0 and belt[0] >= 1: #로봇 올려줌
        robot[0] = 1
        belt[0] -= 1
    res += 1
    if belt.count(0) >= k:
        break

print(res)
