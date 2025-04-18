from itertools import permutations

def solution(numbers):
    nums = [n for n in numbers]
    per = []
    for i in range(1, len(numbers) + 1):
        per += list(permutations(nums, i))
        
    new_nums = set(int("".join(p)) for p in per)
    new_nums -= set(range(0, 2))
    
    for i in range(2, int(max(new_nums) ** 0.5) + 1):
        new_nums -= set(range(i * 2, max(new_nums) + 1, i))
    
    return len(new_nums)
