def solution(numbers):
    answer = ''
    numbers = [str(i) for i in numbers]
    numbers = sorted(numbers,key = lambda x:x*3, reverse = True )
    for i in numbers:
        answer+=i
    return str(int(answer))