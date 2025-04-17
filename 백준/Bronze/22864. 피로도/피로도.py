a, b, c, m = map(int, input().split())
result = 0
pirodo = 0
for _ in range(24):
    if pirodo + a <= m:
        pirodo += a
        result += b
    else:
        pirodo -= c
        pirodo = 0 if pirodo < 0 else pirodo

print(result)
