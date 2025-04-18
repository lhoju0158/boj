def solution(brown, yellow):
    answer = []
    for a in range(1,int(yellow**0.5)+1):
        if yellow % a==0:
            b = yellow//a
            if (a+2)*(b+2)==brown+yellow:
                answer.append(max(a+2,b+2))
                answer.append(min(a+2,b+2))
                break
    return answer