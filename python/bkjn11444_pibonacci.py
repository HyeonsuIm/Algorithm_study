from sys import stdin

def multiply(matrix1, matrix2):
    return \
    [
        [(matrix1[0][0]*matrix2[0][0]+matrix1[0][1]*matrix2[1][0])%1000000007, (matrix1[0][0]*matrix2[0][1]+matrix1[0][1]*matrix2[1][1])%1000000007],
        [(matrix1[1][0]*matrix2[0][0]+matrix1[1][1]*matrix2[1][0])%1000000007, (matrix1[1][0]*matrix2[0][1]+matrix1[1][1]*matrix2[1][1])%1000000007]
    ]



cnt = int(stdin.readline())
if cnt <= 1:
    print(cnt)
else:
    result = [[1,0],[0,1]]
    matrix = [[1,1],[1,0]]
    while cnt > 0:
        if cnt % 2 == 1 :
            result = multiply(result, matrix)
        matrix = multiply(matrix, matrix)
        cnt = (cnt//2)
    print(result[0][1])