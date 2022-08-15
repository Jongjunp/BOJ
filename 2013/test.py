import os
import random

f = open(os.getcwd()+'/test.txt', 'w')
N = 100
f.write(str(N)+"\n")
for _ in range(N):
    x1 = str(round(random.random()*1000,1))
    y1 = str(round(random.random()*1000,1))
    x2 = str(round(random.random()*1000,1))
    y2 = str(round(random.random()*1000,1))
    f.write(x1+" "+y1+" "+x2+" "+y2+"\n")
f.close()