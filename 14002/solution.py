seqSize = int(input())
seq = list(map(int,input().split(" ")))
maxlen = 0
lis = []
answer_li = []
for i,num in enumerate(seq):
    if (not lis) or (num > lis[len(lis)-1]):
        lis.append(num)
        maxlen = len(lis)
        answer_li.append(num)
        continue
    else:
        left = 0
        right = len(lis)-1
        mid = int((left+right)/2)
        while (right > left):
            if (num <= lis[mid]):
                right = mid
            else:
                left = mid+1
            mid = int((left+right)/2)
        lis[mid] = num
        if (maxlen < right):
            maxlen = right
print(maxlen)
print()