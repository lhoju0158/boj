from collections import Counter

n = int(input())
for _ in range(n):
    s = input().replace(" ", "")  # 공백 제거
    counter = Counter(s)  # counter는 map 역할도 한다, key / value
    max_value = max(counter.values())
    most_commons = [k for k, v in counter.items() if v == max_value]
    if len(most_commons) == 1:
        print(most_commons[0])
    else:
        print("?")
