n, m = map(int, input().split())
array = list(map(int, input().split()))  # 공백 있는 입력 대응

for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        array[b - 1] = c
    elif a == 2:
        for i in range(b - 1, c):
            array[i] = (array[i] + 1) % 2
    elif a == 3:
        for i in range(b - 1, c):
            array[i] = 0
    else:
        for i in range(b - 1, c):
            array[i] = 1

print(" ".join(map(str, array)))
