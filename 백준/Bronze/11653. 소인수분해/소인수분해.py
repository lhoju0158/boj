n = int(input())
while True:
    if n == 1:
        break
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                print(i)
                n = n // i
                break
