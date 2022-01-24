import sys
input = sys.stdin.readline


N = int(input())

string_n = str(N)
origin = string_n  # 기존 숫자
if N < 10:
    string_n = '0'+string_n
    origin = string_n


cnt = 0


while(1):
    first = int(string_n[0]) + int(string_n[1])  # 처음 합한 결과
    first = str(first)
    next = first[1] if len(first) > 1 else first  # 길이 비교해서 두자리수면 오른쪽 숫자 선택
    new = string_n[1]+next  # 새로운 숫자

    string_n = new  # 다시 할당해서 비교 반복
    cnt += 1

    if new == origin:
        break

print(cnt)
