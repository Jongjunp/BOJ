test_num = int(input())
for _i in range(test_num):
    (A_num, B_num) = tuple(map(int,input().split(" ")))
    A_list = list(map(int,input().split(" ")))
    B_list = list(map(int,input().split(" ")))
    A_list.sort()
    B_list.sort()
    comb_num = 0
    for a in A_list:
        left = 0
        right = len(B_list)-1
        mid = int((left+right)/2)
        while (left<right):
            if (B_list[mid] < a):
                left = mid+1
            else:
                right = mid
            mid = int((left+right)/2)
        if (B_list[mid] < a):
            comb_num += (mid+1)
        else:
            comb_num += mid
    print(comb_num)