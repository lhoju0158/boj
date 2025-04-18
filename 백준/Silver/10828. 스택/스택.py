import sys

input = sys.stdin.readline

n = int(input())
stack = []

for _ in range(n):
    array = input().split()
    cmd = array[0]

    if cmd == "push":
        stack.append(array[1])
    elif cmd == "pop":
        if stack:
            print(stack[-1])
            stack.pop()
        else:
            print(-1)
    elif cmd == "size":
        print(len(stack))
    elif cmd == "empty":
        print(1 if not stack else 0)
    elif cmd == "top":
        if stack:
            print(stack[-1])
        else:
            print(-1)
