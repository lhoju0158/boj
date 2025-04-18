def solution(clothes):
    answer = 1
    hash_map={}
    for cloth in clothes:
        if cloth[1] in hash_map:
            hash_map[cloth[1]]+=1
        else:
            hash_map[cloth[1]]=1
    for _, h in hash_map.items():
        answer*=(h+1)
    return answer-1