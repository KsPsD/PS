import sys
input = sys.stdin.readline


sen = input().rstrip()

mini = ""
maxi = ""

res = 0
cnt = 0
for ele in sen:
    if ele == 'M':
        cnt += 1
    else:
        if(cnt == 0):

            mini += '5'
            maxi += '5'
        else:
            mini += str((10**cnt)+5)
            maxi += str((10**cnt)*5)
        cnt = 0


if cnt:
    # print(len(st))
    mini += str(10**(cnt-1))
    maxi += '1'*cnt


print(maxi)
print(mini)
