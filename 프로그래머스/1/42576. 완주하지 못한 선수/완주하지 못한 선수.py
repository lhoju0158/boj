from collections import Counter
def solution(participant, completion):
    answer = ''
    counter = Counter(participant)-Counter(completion)
    answer = list(counter.keys())[0]
    return answer