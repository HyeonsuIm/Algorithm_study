from sys import stdin

def is_operator(ch):
    if ch in ['+', '-', '*','/']:
        return True
    else:
        return False


def is_bracket(ch):
    if ch in ('(',')'):
        return True
    else:
        return False

priority = {
    '(':0,
    '+':1,
    '-':1,
    '*':2,
    '/':2,
    ')':0
}


str = stdin.readline().strip()
result = ""
stack = []
for ch in str:
    if is_operator(ch):
        while stack:
            if priority[stack[-1]] >= priority[ch]:
                result += stack.pop()
            else:
                break

        stack.append(ch)
    elif is_bracket(ch):
        if ch == '(':
            stack.append(ch)
        else:
            while stack:
                if stack[-1] != '(':
                    result += stack.pop()
                else:
                    break
            
            if stack:
                if stack[-1] == '(':
                    stack.pop()
    else:
        result += ch

while stack:
    result += stack.pop()

print(result)