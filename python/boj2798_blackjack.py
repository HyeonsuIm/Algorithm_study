from sys import stdin

cnt, value = map(int, stdin.readline().split())
values = list(map(int,stdin.readline().split()))
    
values.sort()
currentMaxVal = 0
for i, value1 in enumerate(reversed(values)):
    for j, value2 in enumerate(values):
        for k, value3 in enumerate(values):
            if value1 != value2 and value2 != value3 and value3 != value1 :
                valueSum = value1 + value2 + value3
                if valueSum <= value and valueSum > currentMaxVal:
                    currentMaxVal = valueSum
                

print(currentMaxVal)