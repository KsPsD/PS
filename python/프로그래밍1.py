import sys
input = sys.stdin.readline

id_list = ["con", "ryan"]
report = ["ryan con", "ryan con", "ryan con", "ryan con"]
k = 3
name_id = {j: i for (i, j) in enumerate(id_list)}
ch = [[0]*len(id_list) for _ in range(len(id_list))]
connect = [[] for _ in range(len(id_list))]

for r in report:
    a, b = r.split(" ")
    if name_id[b] not in connect[name_id[a]]:
        connect[name_id[a]].append(name_id[b])

cnt = [0]*len(id_list)

for i in range(len(connect)):
    for j in range(len(connect[i])):
        if ch[i][j] != 0:
            continue

        cnt[connect[i][j]] += 1
        ch[i][j] = 1
res = [0 for _ in range(len(id_list))]
for i in range(len(cnt)):
    if cnt[i] >= k:
        for j in range(len(id_list)):
            if i in connect[j]:
                res[j] += 1
print(res)
