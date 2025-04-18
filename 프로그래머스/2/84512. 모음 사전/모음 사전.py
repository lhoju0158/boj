from itertools import product
def solution(word):
    answer = 0
    alpa = ['A', 'E', 'I', 'O', 'U']
    arr = []
    for i in range(1,6):
        for p in list(product(alpa,repeat = i)):
            arr.append("".join(p))
    arr.sort()
    
    answer = arr.index(word)+1
    return answer