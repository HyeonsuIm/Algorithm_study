from sys import stdin

cnt = int(stdin.readline())
ans=0
current_cnt = 0
while current_cnt != cnt:
    ans+=1
    temp = ans
    while temp != 0:
        if temp % 1000 == 666:
            current_cnt+=1
            break
        else:
            temp = int(temp/10)

print(ans)