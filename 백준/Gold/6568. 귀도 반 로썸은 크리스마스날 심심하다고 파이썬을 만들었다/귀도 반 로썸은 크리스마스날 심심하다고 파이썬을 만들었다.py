from sys import stdin

while True:
    try:
        memory = [int(stdin.readline().strip(),2) for _ in range(32)]  
    except:
        break

    adder = 0
    pc = 0
    while True:
        op, val = divmod(memory[pc], 32)
        pc = (pc + 1) % 32
        if op == 0:
            memory[val] = adder
        elif op == 1:
            adder = memory[val]
        elif op == 2:
            pc = val if adder == 0 else pc
        elif op == 3:
            continue
        elif op == 4:
            adder = ( adder - 1 ) % 256
        elif op == 5:
            adder = ( adder + 1 ) % 256
        elif op == 6:
            pc = val
        elif op == 7:
            break

    print(f"{adder:08b}")