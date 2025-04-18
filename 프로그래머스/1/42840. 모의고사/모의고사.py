def solution(answers):
    answer = []
    no1 = [1, 2, 3, 4, 5]
    no2 = [2, 1, 2, 3, 2, 4, 2, 5]
    no3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    n1,n2,n3 = 0,0,0
    for i in range(len(answers)):
        if no1[i%len(no1)]==answers[i]:
            n1+=1
        if no2[i%len(no2)]==answers[i]:
            n2+=1
        if no3[i%len(no3)]==answers[i]:
            n3+=1
    if max(n1,n2,n3) == n1:
        answer.append(1)
    if max(n1,n2,n3) == n2:
        answer.append(2)
    if max(n1,n2,n3) == n3:
        answer.append(3)
    return answer