import sys
from types import SimpleNamespace
from dataclasses import dataclass, field
import sys
N, K = map(int, input().split())
numbers = list(map(int, input().split()))
lt, rt = 0, 0
counter = [0] * (max(numbers) + 1)


answer = 0

while rt < N:
    if counter[numbers[rt]] < K:
        counter[numbers[rt]] += 1
        rt += 1
    else:
        counter[numbers[lt]] -= 1
        lt += 1

    answer = max(answer, rt-lt)

print(answer)
