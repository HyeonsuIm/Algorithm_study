from sys import stdin
from math import log10
from math import floor

value = int(stdin.readline().rstrip())
digits = floor(log10(value)) + 1
result=0
rangeStart = 0
if value-digits*10 > 0:
    rangeStart = value-digits*10
    
for checkVal in range(rangeStart, value):
    decompositionSum = checkVal + sum([int(i) for i in str(checkVal)])
    if value == decompositionSum:
        result=checkVal
        break

print(result)