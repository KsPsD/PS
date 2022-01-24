import sys

input = sys.stdin.readline

price = 3
money = 20
count = 4

cur = 0
sum = 0
for i in range(1, count+1):
    cur = price*i
    sum += cur

if sum < money:
    print(0)

else:
    print(abs(money-sum))
