import math

def solution(s):
    is_answer_found=False
    answer = 0
    #숫자반복, 전체 길이의 중간까지
    find_length = math.floor(len(s) / 2) + 1
    for check_length in range(1, find_length):
        #자른 결과 찾기
        encoded_str=get_shotest_encoded_str(s, check_length)
        #print(encoded_str)
        encoded_str_length=len(encoded_str)
        if is_answer_found is True and encoded_str_length!=0:
            if answer > encoded_str_length:
                answer = encoded_str_length
        else:
            is_answer_found=True
            answer=encoded_str_length
            
    if answer==0:
        answer=len(s)
    return answer

def get_shotest_encoded_str(string, check_length):
    encoded_str = ""
    str_length = len(string)
    cnt=0
    for i in range(0, len(string), check_length):
        if string[i:i+check_length] != string[i+check_length:i+check_length+check_length]:
            if cnt != 0:
                encoded_str += str(cnt+1)
            encoded_str += string[i:i+check_length]
        else
            cnt += 1
    return encoded_str

def get_max_encode_count(string, check_start_index, check_length):
    string_len = len(string)
    can_encode = True
    encode_count=0
    additional_check_count=0
    check_start_index_first = check_start_index
    while can_encode is True:
        check_start_index = check_start_index_first + (additional_check_count * check_length)
        if check_start_index > string_len-check_length-1:
            break

        can_encode = check_encode_possible(string, check_start_index, check_length)
        if can_encode is True:
            additional_check_count+=1
            if encode_count==0:
                encode_count=2
            else:
                encode_count+=1
    return encode_count

def check_encode_possible(string, start_index, check_length):
    is_encode_possible=True
    for check_index in range(start_index, start_index + check_length):
        if string[check_index] != string[check_index + check_length]:
            is_encode_possible = False
            break
    return is_encode_possible

if __name__ == "__main__":
    s = "abcabcdede"
    result = solution(s)
    print(result)