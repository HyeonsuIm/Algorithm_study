from sys import stdin

sum_value = int(stdin.readline().rstrip())
is_used = [False for _ in range(sum_value+1)]

prime_list=[]
for i in range(2, sum_value+1):
    if is_used[i]==True:
        continue    
    
    prime_list.append(i)
    for k in range(0, sum_value+1, i):
        is_used[k]=True
            

sum_dict={}
sum_dict[str(0)]=1
sum=0
count=0
for i in prime_list:
    sum+=i
    check_val = sum-sum_value
    if str(check_val) in sum_dict:
        count += sum_dict[str(check_val)]
    
    if str(sum) in sum_dict:
        sum_dict.update({str(sum):int(sum_dict[str(sum)])+1})
    else:
        sum_dict.update({str(sum):1})

print(count)