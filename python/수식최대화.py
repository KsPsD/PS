import sys
from collections import defaultdict
from itertools import permutations
from copy import deepcopy
input = sys.stdin.readline

opr = ['-', '*', '+']
expression = '100-200*300-500+20'
cmd = defaultdict(list)
cur_num = ""
num_list = []


def calc(num1, num2, op):

    if op == '+':
        return int(num1) + int(num2)
    if op == '-':
        return int(num1) - int(num2)
    if op == '*':
        return int(num1) * int(num2)


for idx in range(len(expression)):
    if expression[idx] in opr:
        num_list.append(int(cur_num))
        num_list.append(expression[idx])
        cur_num = ""
    else:
        cur_num += expression[idx]

if cur_num:
    num_list.append(int(cur_num))


res = []
nf = list(permutations(opr))

for cur_op in nf:
    cur_num_list = deepcopy(num_list)
    for op in cur_op:
        st = []
        while len(cur_num_list) != 0:
            tmp = cur_num_list.pop(0)
            if tmp == op:
                st.append(calc(st.pop(), cur_num_list.pop(0), op))
            else:
                st.append(tmp)

        cur_num_list = st

    res.append(abs(cur_num_list[0]))

print(max(res))
