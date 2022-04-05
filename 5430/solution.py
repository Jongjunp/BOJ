import sys
from collections import deque
test_num = int(input())
for i in range(test_num):
    flag = True
    com_list = sys.stdin.readline().rstrip()
    arr_len = int(input())
    arr = deque(sys.stdin.readline().rstrip()[1:-1].split(","))
    if arr_len==0:
        arr = deque()
    stack = 0
    for com in com_list:
        if com == 'R':
            stack += 1
        elif com=='D' and arr:
            if (stack%2==0):
                arr.popleft()
            else:
                arr.pop()
        else:
            flag = False
            break
    if flag:
        if (stack%2==1):
            arr.reverse()
        text = '['+','.join(arr)+']'
        print(text)
    else:
        print('error')