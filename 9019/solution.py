import sys
from collections import deque

testnum = int(input())
for _i in range(testnum):
    input_li = input().split(' ')
    src = int(input_li[0])
    dest = int(input_li[1])
    ref = [True]*10000
    ref[src] = False
    queue = deque()
    queue.append((src,""))
    while queue:
        num,oper = queue.popleft()
        d_num = (num*2)%10000
        s_num = (num-1)%10000
        l_num = ((num*10)%10000)+((num*10)//10000)
        r_num = (num//10)+((num%10)*1000)
        if (num == dest):
            print(oper)
            break
        if ref[d_num]:
            queue.append((d_num,oper+"D"))
            ref[d_num] = False
        if ref[s_num]:
            queue.append((s_num,oper+"S"))
            ref[s_num] = False
        if ref[l_num]:
            queue.append((l_num,oper+"L"))
            ref[l_num] = False
        if ref[r_num]:
            queue.append((r_num,oper+"R"))
            ref[r_num] = False