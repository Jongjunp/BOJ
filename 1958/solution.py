targ1 = input()
targ2 = input()
targ3 = input()
table = [[[0 for _ in range(len(targ3)+1)] for _ in range(len(targ2)+1)] for _ in range(len(targ1)+1)]
lcs_len = 0
lcs = ''
for idx1 in range(len(targ1)):
    for idx2 in range(len(targ2)):
        for idx3 in range(len(targ3)):
            if (targ1[idx1]==targ2[idx2] and targ1[idx1]==targ3[idx3]):
                table[idx1+1][idx2+1][idx3+1] = table[idx1][idx2][idx3] + 1
            else:
                table[idx1+1][idx2+1][idx3+1] = max((table[idx1+1][idx2][idx3],
                                                    table[idx1][idx2+1][idx3],
                                                    table[idx1][idx2][idx3+1],
                                                    table[idx1+1][idx2+1][idx3],
                                                    table[idx1+1][idx2][idx3+1],
                                                    table[idx1][idx2+1][idx3+1]))
            if (lcs_len<table[idx1+1][idx2+1][idx3+1]):
                lcs_len += 1
print(lcs_len)
