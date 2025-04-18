def solution(phone_book):
    answer = True
    hash_map = {}
    for i in phone_book:
        hash_map[i]=1
    for phone_number in hash_map:
        j =""
        for i in phone_number:
            j+=i
            if j in hash_map and j !=phone_number:
                return False

    return True