def solution(prices):
    answer = []
    answer = [i for i in range(len(prices)-1,-1,-1)]
    stack = [0]
    for i in range(1,len(prices)):
        while stack and prices[stack[-1]] > prices[i]: # 
            n = stack.pop()
            answer[n] = i-n
        stack.append(i)
    return answer