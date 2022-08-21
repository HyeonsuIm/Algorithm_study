from sys import stdin

data_cnt, same_cnt = map(int,stdin.readline().split())
string_list=[]
same_dict = {}

def make_str_key(str, i):
    result = ""
    for j in range(4):
        if i &(1 << j) != 0:
            result += '*'
        else:
            result += str[j]
    return result


def solve1(data_cnt, string_list, same_dict):
    cnt = 0
    for i in range(data_cnt):
        cnt+=same_dict[make_str_key(string_list[i], 1)]
        cnt+=same_dict[make_str_key(string_list[i], 2)]
        cnt+=same_dict[make_str_key(string_list[i], 4)]
        cnt+=same_dict[make_str_key(string_list[i], 8)]
    return cnt


def solve2(data_cnt, string_list, same_dict):
    cnt = 0
    for i in range(data_cnt):
        cnt+=same_dict[make_str_key(string_list[i], 3)]
        cnt+=same_dict[make_str_key(string_list[i], 5)]
        cnt+=same_dict[make_str_key(string_list[i], 9)]
        cnt+=same_dict[make_str_key(string_list[i], 6)]
        cnt+=same_dict[make_str_key(string_list[i], 10)]
        cnt+=same_dict[make_str_key(string_list[i], 12)]
        
        cnt-=3*same_dict[make_str_key(string_list[i], 1)]
        cnt-=3*same_dict[make_str_key(string_list[i], 2)]
        cnt-=3*same_dict[make_str_key(string_list[i], 4)]
        cnt-=3*same_dict[make_str_key(string_list[i], 8)]
        
    return cnt


def solve3(data_cnt, string_list, same_dict):
    cnt = 0
    for i in range(data_cnt):
        cnt+=same_dict[make_str_key(string_list[i], 7)]
        cnt+=same_dict[make_str_key(string_list[i], 11)]
        cnt+=same_dict[make_str_key(string_list[i], 13)]
        cnt+=same_dict[make_str_key(string_list[i], 14)]
        
        cnt-=2*same_dict[make_str_key(string_list[i], 3)]
        cnt-=2*same_dict[make_str_key(string_list[i], 5)]
        cnt-=2*same_dict[make_str_key(string_list[i], 9)]
        cnt-=2*same_dict[make_str_key(string_list[i], 6)]
        cnt-=2*same_dict[make_str_key(string_list[i], 10)]
        cnt-=2*same_dict[make_str_key(string_list[i], 12)]
        
        cnt+=3*same_dict[make_str_key(string_list[i], 1)]
        cnt+=3*same_dict[make_str_key(string_list[i], 2)]
        cnt+=3*same_dict[make_str_key(string_list[i], 4)]
        cnt+=3*same_dict[make_str_key(string_list[i], 8)]
        
        
    return cnt
    
for _ in range(data_cnt):
    str = stdin.readline().rstrip()
    string_list.append(str)
    for i in range(1,17):
        key = make_str_key(str, i)
        if key in same_dict:
            same_dict[key]+=1
        else:
            same_dict.update({key:0})

if same_cnt == 1:
    print(int(solve1(data_cnt, string_list, same_dict)/2))
elif same_cnt==2:
    print(int(solve2(data_cnt, string_list, same_dict)/2))
elif same_cnt==3:
    print(int(solve3(data_cnt, string_list, same_dict)/2))
else:
    print(int((data_cnt * (data_cnt-1) - solve1(data_cnt, string_list, same_dict) - solve2(data_cnt, string_list, same_dict) - solve3(data_cnt, string_list, same_dict))/2))

