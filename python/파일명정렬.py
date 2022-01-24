import sys
input = sys.stdin.readline


def solution(files):

    file_dict = {}

    for f in files:
        head = ""
        number = ""
        tail = ""
        ch = False
        for i in range(len(f)):
            if f[i].isdigit():
                number += f[i]
                ch = True
            elif not ch:
                head += f[i]

            else:
                tail = f[i:]
                break
        file_dict[f] = (head, int(number), tail)
        # answer.append((head, number, tail))
# file_list.sort(key=lambda x: len(str(x[1])))

    ans = dict(sorted(file_dict.items(),
                      key=lambda x: (x[1][0].upper(), x[1][1])))
    # answer.sort(key=lambda x: (x[0].upper(), int(x[1])))

    return list(ans.keys())
