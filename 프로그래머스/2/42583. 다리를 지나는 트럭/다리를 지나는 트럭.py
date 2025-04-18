def solution(bridge_length, weight, truck_weights):
    answer = 0
    queue = [0] * bridge_length
    current_weight = 0
    while queue:
        current_weight-=queue[0]
        queue.pop(0)
        if truck_weights:
            if current_weight + truck_weights[0] <= weight:
                current_weight+=truck_weights[0]
                queue.append(truck_weights.pop(0))
            else:
                queue.append(0)
        answer += 1

    return answer
