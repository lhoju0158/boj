n = int(input())
result = 0
data = dict()
for _ in range(n):
    a, b = map(int, input().split())
    if a in data:
        if data[a] != b:
            result += 1
            data[a] = b
    else:
        data[a] = b
print(result)
