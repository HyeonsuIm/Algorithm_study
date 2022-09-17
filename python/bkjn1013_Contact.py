from sys import stdin

first_pattern = ['10','01']
second_pattern =['0','1']

def CheckSignalSecondPattern(signal, check_type, is_first_check):
    if signal:
        if check_type == 0:
            if signal[0] == second_pattern[0]:
                return CheckSignalSecondPattern(signal[1:], 0, False)
            else:
                if is_first_check :
                    return False
                else:
                    return CheckSignalSecondPattern(signal, 1, True)
        else:
            if is_first_check:
                if signal[0] == second_pattern[1]:
                    return CheckSignalSecondPattern(signal[1:], 1, False)
                else:
                    return False
            else:
                for case in range(2):
                    if case == 0:
                        if signal[:2] == first_pattern[0]:
                            result= CheckSignalFirstPatten(signal)
                            if result == True:
                                return result
                    else:
                        if signal[0] == second_pattern[1]:
                            return CheckSignalSecondPattern(signal[1:], 1, False)
                        else:
                            return CheckSignalFirstPatten(signal)
    else:
        if check_type == 0:
            return False
        else:
            if is_first_check:
                return False
            else:
                return True
    


def CheckSignalFirstPatten(signal):
    if signal:
        if signal[:2] == first_pattern[0]:
            return CheckSignalSecondPattern(signal[2:], 0, True)
        elif signal[:2] == first_pattern[1]:
            return CheckSignalFirstPatten(signal[2:])
        else:
            return False
    else:
        return True

problem_cnt = int(stdin.readline().rstrip())
for _ in range(problem_cnt):
    signal_pattern = stdin.readline().rstrip()
    result = CheckSignalFirstPatten(signal_pattern)

    if result == True:
        print("YES")
    else:
        print("NO")