import math

n = int(input())
a = list(map(int, input().split()))
b, c = map(int, input().split())

result = 0

for i in a:
    result += 1
    remain = i - b
    if remain > 0:
        result += math.ceil(remain / c)

print(result)
