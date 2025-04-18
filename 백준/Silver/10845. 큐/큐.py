from collections import deque
import sys

input = sys.stdin.readline

n = int(input())
dq = deque()

for _ in range(n):
    array = input().split()
    cmd = array[0]
    if cmd == "push":
        dq.append(array[1])
    elif cmd == "pop":
        print(dq.popleft() if dq else -1)
    elif cmd == "empty":
        print(0 if dq else 1)
    elif cmd == "size":
        print(len(dq))
    elif cmd == "front":
        print(dq[0] if dq else -1)
    else:
        print(dq[-1] if dq else -1)
