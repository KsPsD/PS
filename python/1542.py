import sys
input = sys.stdin.readline

exp = input().rstrip()

exp += 'e'
ans = 0
tmp = ""
flag = False
for i in range(len(exp)):
    if exp[i] == '-' or exp[i] == '+' or exp[i] == 'e':
        if flag:
            ans -= int(tmp)
        else:
            ans += int(tmp)

        tmp = ""

        if exp[i] == '-':
            flag = True
        continue

    tmp += exp[i]

print(ans)
