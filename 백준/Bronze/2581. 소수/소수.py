m = int(input())
n = int(input())


def is_prime(a):
    if a < 2:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True


array = [i for i in range(m, n + 1) if is_prime(i)]
if len(array) == 0:
    print(-1)
else:
    print(sum(array))
    print(min(array))
