from sys import stdin
from sys import setrecursionlimit

global scc_cnt
global scc_stack
global visit_cnt

def GetInputs():
    city_cnt, trip_cnt, start, end = map(int,stdin.readline().split())
    trip_list=[[] for _ in range(city_cnt+1)]
    for i in range(trip_cnt):
        from_city, to_city = map(int, stdin.readline().split())
        trip_list[from_city].append(to_city)
        
    return city_cnt, trip_list, start, end


def VisitCity(current_city, visit_city_cnt, visited_cities, trip_list, goal):
    max_visit_cnt = 0;
    next_visit_city_cnt= visit_city_cnt
    is_added=False
    if visited_cities[current_city] is False:
        is_added = True
        visited_cities[current_city]=True
        next_visit_city_cnt=visit_city_cnt+1
    
    for trip_info in trip_list[current_city]:
        if max_visit_cnt == len(visited_cities)-1:
            break
        if trip_info.is_used is False:
            trip_info.is_used = True
            visit_cnt = VisitCity(trip_info.to_city, next_visit_city_cnt, visited_cities, trip_list, goal)
            if max_visit_cnt < visit_cnt:
                max_visit_cnt = visit_cnt
            trip_info.is_used = False

    if current_city == goal:
        if max_visit_cnt < next_visit_city_cnt:
            max_visit_cnt = next_visit_city_cnt
            
    if is_added is True:
        visited_cities[current_city]=False
    return max_visit_cnt


def MakeSCC(city_idx, visit_order_list, trip_list, scc_result, country_count_in_scc):
    global scc_cnt
    global scc_stack
    global visit_cnt
    scc_stack.append(city_idx)
    visit_order_list[city_idx]=visit_cnt
    curr_idx = visit_cnt
    visit_cnt+=1
    
    for next_city_idx in trip_list[city_idx]:
        if visit_order_list[next_city_idx] == -1:
            curr_idx = min(curr_idx,MakeSCC(next_city_idx, visit_order_list, trip_list, scc_result, country_count_in_scc))
        elif scc_result[next_city_idx] == -1:
            curr_idx = min(curr_idx,visit_order_list[next_city_idx])
        
    if curr_idx == visit_order_list[city_idx]:
        while True:
            here_idx = scc_stack.pop()
            scc_result[here_idx] = scc_cnt
            country_count_in_scc[scc_cnt] += 1
            if here_idx == city_idx:
                break
        scc_cnt+=1
    return curr_idx
            
    
def Make_SCC_trip_list(city_cnt, trip_list, scc):
    scc_trip_list = [[] for _ in range(len(scc))]
    for i in range(1, city_cnt+1):
        for curr in trip_list[i]:
            if scc[i] != scc[curr]:
                scc_trip_list[scc[i]].append(scc[curr])
    return scc_trip_list


def GetMaximumCityVisit(city_cnt, trip_list, start, end):
    global scc_cnt
    scc_cnt =1
    global scc_stack
    scc_stack = []
    global visit_cnt
    visit_cnt = 0
    scc_result = [-1 for _ in range(city_cnt+1)]
    visit_order_list = [-1 for _ in range(city_cnt+1)]
    country_count_in_scc = [0 for _ in range(city_cnt+1)]
    for i in range(1, city_cnt+1):
        if visit_order_list[i] == -1:
            MakeSCC(i, visit_order_list, trip_list, scc_result, country_count_in_scc)
    
    scc_trip_list = Make_SCC_trip_list(city_cnt, trip_list, scc_result)
    stack = []
    start_scc = scc_result[start]
    goal_scc = scc_result[end]
    
    if start_scc == goal_scc:
        return country_count_in_scc[start_scc]
    else:
        city_visit_cnt = [0 for _ in range(len(scc_result)+1)]
        stack.append(start_scc)
        city_visit_cnt[start_scc] = country_count_in_scc[start_scc]
        while stack:
            curr_scc = stack.pop()
            for next_scc in scc_trip_list[curr_scc]:
                if city_visit_cnt[next_scc] < city_visit_cnt[curr_scc] + country_count_in_scc[next_scc]:
                    city_visit_cnt[next_scc] = city_visit_cnt[curr_scc] + country_count_in_scc[next_scc]
                    stack.append(next_scc)

        return city_visit_cnt[goal_scc]

            
if __name__ == "__main__":
    setrecursionlimit(1000000)
    city_cnt, trip_list, start, end = GetInputs()
    print(GetMaximumCityVisit(city_cnt, trip_list, start, end))