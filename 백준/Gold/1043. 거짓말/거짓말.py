from sys import stdin


person_num, party_cnt = map(int,stdin.readline().split())
do_not_lie_person_cnt, *do_not_lie_person_list = list(map(int,stdin.readline().split()))

party_member_list = []
for _ in range(party_cnt):
    _, *party_members = list(map(int, stdin.readline().split()))
    party_member_list.append(party_members)

party_attend_bitmask_per_member = [0 for _ in range(person_num+1)]
for i, party_member in enumerate(party_member_list):
    bit_mask = 1 << i
    for member in party_member:
        party_attend_bitmask_per_member[member] += bit_mask


DO_NOT_LIE_PARTY_BITMASK = 0
for i in do_not_lie_person_list:
    DO_NOT_LIE_PARTY_BITMASK |= party_attend_bitmask_per_member[i]

while True:
    temp = DO_NOT_LIE_PARTY_BITMASK
    for i, bitmask in enumerate(party_attend_bitmask_per_member):
        if bitmask & DO_NOT_LIE_PARTY_BITMASK != 0:
            DO_NOT_LIE_PARTY_BITMASK |= bitmask

    if temp == DO_NOT_LIE_PARTY_BITMASK:
        break

PARTY_CNT = 0
for i in range(party_cnt):
    if ((DO_NOT_LIE_PARTY_BITMASK >> i) & 1) == 0:
        PARTY_CNT += 1
print(PARTY_CNT)
