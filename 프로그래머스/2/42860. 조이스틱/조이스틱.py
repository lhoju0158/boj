       
def solution(name):
    answer = 0
    spell = 0
    cursor = len(name)-1 # 최대
    for i, s in enumerate(name):
        spell+=min(ord(s)-ord("A"),ord("Z")-ord(s)+1)
        next = i+1
        while next<len(name) and name[next]=="A":
            next+=1
        distance = min(i, len(name) - next)
        cursor = min(cursor, i + len(name) - next + distance)
        
        
    return cursor + spell