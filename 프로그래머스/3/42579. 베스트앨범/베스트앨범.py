def solution(genres, plays):
    answer = []
    hash1 = {} # 장르 + (index, 재생 수)
    hash2 = {} # 장르 + 총 재생 수
    for i , (g, p) in enumerate(zip(genres, plays)):
        if g not in hash1:
            hash1[g] = [(i, p)]
        else:
            hash1[g].append((i, p))
        if g not in hash2:
            hash2[g] = p
        else:
            hash2[g]+=p
    ## 
    for (g, tp) in sorted(hash2.items(), key = lambda x:x[1], reverse = True):
        for (i, p) in sorted(hash1[g], key = lambda x:x[1], reverse = True)[:2]:
            answer.append(i)
    
    return answer