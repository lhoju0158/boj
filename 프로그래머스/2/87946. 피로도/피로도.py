from itertools import permutations

def solution(k, dungeons):
    answer = 0
    for perm in permutations(dungeons, len(dungeons)):
        now_k = k
        count = 0
        for need, consume in perm:
            if now_k >= need:
                now_k -= consume
                count += 1
            else:
                break
        answer = max(answer, count)
    return answer
