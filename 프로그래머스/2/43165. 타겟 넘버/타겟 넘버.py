def solution(numbers, target):
    answer = 0

    def dfs(index, now):
        nonlocal answer  
        if index == len(numbers):
            if now == target:
                answer += 1
            return
        dfs(index + 1, now + numbers[index])
        dfs(index + 1, now - numbers[index])
    
    dfs(0, 0)
    return answer
