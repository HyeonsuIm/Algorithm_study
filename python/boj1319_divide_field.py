from sys import stdin

class Coord:
    x:int = None
    y:int = None
    
    def __init__(self, x,y):
        self.x=x
        self.y=y
    

class TreeInfo:
    coordinate:Coord=None
    value:int
    
    def __init__(self, x,y,value):
        self.coordinate=Coord(x,y)
        self.value=value

def GetInputs():
    cnt = int(stdin.readline())

    tree_point_list=[]
    for i in range(cnt):
        x, y, value = map(int, stdin.readline().split())
        tree_point_list.append(TreeInfo(x,y,value))
        
    return tree_point_list


def MoveCoordToCenter(tree_point_list):
    point_list = [tree_info.coordinate for tree_info in tree_point_list]
    min_coord, _ = GetCoordRange(point_list)
    new_tree_point_list = list(tree_point_list)
    for coordinate in new_tree_point_list:
        coordinate.coordinate.x -= min_coord.x
        coordinate.coordinate.y -= min_coord.y
    return new_tree_point_list
        

def MakeSlopeList(point_list):
    slope_list=[]
    for i, point_i in enumerate(point_list):
        for j, point_j in enumerate(point_list):
            if i != j:
                min_point = point_i
                max_point = point_j
                if point_i.x > point_j.x or (point_i.x == point_j.x and point_i.y > point_j.y):
                    min_point = point_j
                    max_point = point_i
                
                if max_point.x-min_point.x == 0:
                    continue
                slope = (max_point.y-min_point.y)/(max_point.x-min_point.x)
                slope_list.append(slope)
                
    unique_slope_list = list(set(slope_list))
    return unique_slope_list


def GetCoordRange(point_list):
    minXY=Coord(1000,1000)
    maxXY=Coord(0,0)
    for coordinate in point_list:
        if coordinate.x < minXY.x:
            minXY.x=coordinate.x
            
        if coordinate.y < minXY.y:
            minXY.y=coordinate.y
            
        if coordinate.x > maxXY.x:
            maxXY.x = coordinate.x
        
        if coordinate.y > maxXY.y:
            maxXY.y = coordinate.y
    
    return minXY, maxXY


def GetDiffValue(tree_point_list, start_point, slope):
    sum_a=0
    sum_b=0
    for tree_info in tree_point_list:
        expect_y = slope*(tree_info.coordinate.x-start_point.x)+start_point.y
        if expect_y > tree_info.coordinate.y:
            sum_a += tree_info.value
        else:
            sum_b += tree_info.value
                
    return abs(sum_a-sum_b)
    

def GetMinDiffArea(tree_point_list):
    tree_point_list=MoveCoordToCenter(tree_point_list)
    #field = MakeField(tree_point_list)
    point_list = [tree_info.coordinate for tree_info in tree_point_list]
    slope_list = MakeSlopeList(point_list)
    slope_list.append(0)
    slope_list.append(10000)
    min_diff = 0
    is_first = True
    for tree_info in tree_point_list:
        for slope in slope_list:
            diff = GetDiffValue(tree_point_list, tree_info.coordinate, slope)
            if min_diff > diff or is_first is True:
                min_diff = diff
                is_first=False
            if min_diff == 0:
                break
        if min_diff == 0:
            break
    return min_diff


if __name__ == "__main__":
    tree_point_list = GetInputs()
    print(GetMinDiffArea(tree_point_list))