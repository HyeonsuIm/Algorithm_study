from sys import stdin

def GetInputs():
    cnt = int(stdin.readline())

    drawing_list=[]
    for i in range(cnt):
        start_point, end_point = map(int, stdin.readline().split())
        drawing_list.append((start_point,end_point))
        
    return drawing_list

def GetDrawingLength(drawing_list):
    drawing_list.sort()
    last_end_point=-1000000000
    drawing_length=0
    for start_point, end_point in drawing_list:
        if last_end_point <= start_point:
            drawing_length += end_point-start_point
            last_end_point=end_point
        elif start_point < last_end_point and end_point > last_end_point:
            drawing_length += end_point-last_end_point
            last_end_point=end_point
    return drawing_length
            

if __name__ == "__main__":
    drawing_list = GetInputs()
    print(GetDrawingLength(drawing_list))