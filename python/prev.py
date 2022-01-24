import sys
from itertools import combinations
input = sys.stdin.readline


info = ["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150",
        "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
         "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"]


db = {}

for data in info:
    tmp = data.split()
    cond = tmp[:-1]
    score = tmp[-1]
    for i in range(5):
        combi = list(combinations(range(4), i))
        for c in combi:
            c_c = combi.copy()
            for t in c:
                c_c[t] = '-'
            change_c = '/'.join(c_c)
            if change_c in db:
                db[change_c].append(score)
            else:
                db[change_c] = [score]

for value in db.values():
    value.sort()
for q in query:
    qry = [i for i in q.split() if i != 'and']
    qry_c = '/'.join(qry)
    qry_score = int(qry[-1])
    if qry_c in db:
        data = db[qry_c]
        if len(data) > 0:
            start, end = 0, len(data)
            while start != end and start != len(data):
                if data[(start+end)//2] >= qry_score:
                    end = (start+end)//2
                else:
                    start = (start+end)//2 + 1
