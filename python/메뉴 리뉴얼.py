import sys
from itertools import combinations
from collections import Counter
input = sys.stdin.readline

orders = ["XYZ", "XWY", "WXA"]
coures = [2, 3, 4]
answer = []
for c in coures:
    cur_set = []
    for order in orders:
        comb = combinations(sorted(order), c)
        cur_set += comb

    cnt_dict = Counter(cur_set)
    print(cnt_dict)
    if len(cnt_dict):
        max_course = max(cnt_dict.values())
        if max_course >= 2:
            for k, v in cnt_dict.items():
                if(v == max_course):
                    answer.append(''.join(k))

answer.sort()
print(answer)
