def solution(people, limit):
    answer = 0
    people.sort()
    ## 투포인터
    st = 0
    en = len(people) - 1
    twos = 0
    while st < en:
        if people[st] + people[en] <= limit:
            st+=1
            twos+=1
        en-=1
    answer = len(people) - twos        
    
    return answer