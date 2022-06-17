from itertools import combinations_with_replacement
def count_control():
    init_channel = [1,0,0]
    targ_channel = list(map(int, list(input())))
    num_malfunction = int(input())
    if num_malfunction==0:
        if targ_channel==init_channel:
            print(0)
            return
        else:
            print(len(targ_channel))
            return
    if num_malfunction!=0:
        malfunction_list = list(map(int, input().split(' ')))
    if targ_channel == init_channel:
        print(0)
        return
    possible_num_set = set(0,1,2,3,4,5,6,7,8,9)
    possible_num_set = possible_num_set-set(malfunction_list)
    possible_channel_list = combinations_with_replacement(list(possible_num_set),len(targ_channel))
    start = 0
    end = len(possible_channel_list)-1
    mid = int((start+end)/2)
    while (start<end):
        if (targ_channel):

        else:
            
    function_list = []
    for button in range(10):
        if not button in malfunction_list:
            function_list.append(button)
    temp_channel = []
    count = 0
    for num in targ_channel:
        temp_channel.append(min(function_list, key=lambda x: abs(x-num)))
        count += 1
    temp_channel = list(map(str, temp_channel))
    targ_channel = list(map(str, targ_channel))
    count += abs(int(''.join(temp_channel))-int(''.join(targ_channel)))
    print(count)
    return

count_control()