def solution(sizes):
    answer = 0
    a=0
    b=0
    for i in range(len(sizes)):
        sizes[i]=sorted(sizes[i])
        a=max(a,sizes[i][0])
        b =max(b,sizes[i][1])
    answer = a*b
    return answer