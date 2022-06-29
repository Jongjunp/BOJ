targ1 = input()
targ2 = input()
table = [[0 for _ in range(len(targ2)+1)] for _ in range(len(targ1)+1)]
lcs_len = 0
lcs = ''
for idx1 in range(len(targ1)):
    for idx2 in range(len(targ2)):
        if (targ1[idx1]==targ2[idx2]):
            table[idx1+1][idx2+1] = table[idx1][idx2] + 1
        else:
            if (table[idx1][idx2+1] >= table[idx1+1][idx2]):
                table[idx1+1][idx2+1] = table[idx1][idx2+1]
            else:
                table[idx1+1][idx2+1] = table[idx1+1][idx2]
        if (lcs_len<table[idx1+1][idx2+1]):
            lcs_len += 1
index1 = len(targ1)
index2 = len(targ2)
val = table[index1][index2]
while(val!=0):
    if (val==table[index1-1][index2]):
        index1 -= 1
        continue
    if (val==table[index1][index2-1]):
        index2 -= 1
        continue
    val = table[index1-1][index2-1]
    lcs += targ1[index1-1]
    index1 -= 1
    index2 -= 1
print(lcs_len)
print(lcs[::-1])