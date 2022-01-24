import math


def change(n, q):
    rev_base = ''

    while n > 0:
        n, mod = divmod(n, q)
        rev_base += str(mod)

    return rev_base[::-1]


def is_prime_number(n):
    array = [True for i in range(n+1)]
    array[1] = False
    # 에라토스테네스의 체
    for i in range(2, int(math.sqrt(n)) + 1):
        if array[i] == True:
            j = 2
            while i * j <= n:
                array[i * j] = False
                j += 1

    if(array[n] == True):
        return True
    else:
        return False


number = change(437674, 3)
cur = ""
ans = 0
n = 1000000
array = [True for i in range(n+1)]
array[1] = False
# 에라토스테네스의 체
for i in range(2, int(math.sqrt(n)) + 1):
    if array[i] == True:
        j = 2
        while i * j <= n:
            array[i * j] = False
            j += 1

for ele in number:
    if ele != '0':
        cur += ele
    else:
        if cur != "" and array[int(cur)]:

            ans += 1
            cur = ""
        else:
            cur = ""

if cur != "" and array[int(cur)]:
    ans += 1
print(ans)
