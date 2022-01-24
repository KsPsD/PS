import sys
input = sys.stdin.readline


M, N, L = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
animal = []

arr.sort()

for _ in range(N):
    x, y = map(int, input().strip().split())
    animal.append([x, y])


cnt = 0
for i in range(len(animal)):
    lt, rt = 0, M-1

    while lt <= rt:
        mid = (lt+rt)//2
        cal = abs(arr[mid]-animal[i][0])+animal[i][1]
        if cal <= L:
            cnt += 1
            break
        else:
            if animal[i][0] >= arr[mid]:
                lt = mid+1
            else:
                rt = mid-1


print(cnt)
