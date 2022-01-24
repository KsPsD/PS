import sys
input = sys.stdin.readline

ch = [1]*1000  # 1000개 이하 숫자들에서 가능여부 판단

for num in range(123, 1000):  # 0 을 갖고 있거나 같은 수 갖는 수들 미리 제외시킴
    num_s = str(num)
    if num_s[0] == num_s[1] or num_s[1] == num_s[2] or num_s[0] == num_s[2]:
        ch[num] = 0
    if num_s[0] == '0' or num_s[1] == '0' or num_s[2] == '0':
        ch[num] = 0


N = int(input())
cnt = 0


for i in range(N):
    t, s, b = map(int, input().rstrip().split())
    target = str(t)
    for j in range(123, 1000):
        if ch[j] == 1:  # 주어진 조건과 현재 수의 조건들 파악 하는 부분
            cur = str(j)
            cur_s = 0
            cur_b = 0
            for idx_a in range(3):
                for idx_b in range(3):
                    if idx_a == idx_b and target[idx_a] == cur[idx_b]:
                        cur_s += 1
                    elif idx_a != idx_b and target[idx_a] == cur[idx_b]:
                        cur_b += 1

            if cur_s != s or cur_b != b:  # 만약 주어진 조건 같지 않다면 지워줌
                ch[j] = 0


for i in range(123, 1000):  # 체크되어 있는 수들 갯수 세면됨
    if ch[i] == 1:
        cnt += 1
print(cnt)
