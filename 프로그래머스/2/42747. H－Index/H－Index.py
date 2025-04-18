def solution(citations):
    answer = len(citations)
    citations = sorted(citations,reverse=True)
    for i in range(len(citations)):
        if citations[i]<i+1:
            answer = i
            break
    return answer