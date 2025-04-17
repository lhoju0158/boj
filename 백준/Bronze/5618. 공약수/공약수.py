import math

n = int(input())
array = list(map(int, input().split()))
g = 0
if n == 2:
    g = math.gcd(array[0], array[1])
else:
    g = math.gcd(array[0], array[1], array[2])
result = set()
for i in range(1, int(g**0.5) + 1):
    if (g % i) == 0:
        result.add(i)
        result.add(g // i)

for num in sorted(result):
    print(num)
