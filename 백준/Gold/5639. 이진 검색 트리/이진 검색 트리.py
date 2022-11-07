from sys import stdin
from sys import setrecursionlimit

def postorder(datas, start, end):
    if start > end:
        return
    
    mid = end+1
    for i in range(start+1, end+1):
        if datas[start] < datas[i]:
            mid = i
            break
    
    postorder(datas, start+1, mid-1)
    postorder(datas, mid, end)
    print(datas[start])

setrecursionlimit(1000000)
datas = []
while True:
    try:
        datas.append(int(stdin.readline()))
    except:
        break

postorder(datas, 0, len(datas)-1)