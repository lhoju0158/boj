def solution(s):
    answer = True
    number = 0
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    print('Hello Python')
    for i in s:
        if i =="(":
            number+=1
            continue
        elif i == ")":
            if number==0:
                return False
            else:
                number-=1
    if number>0:
        return False
    return True