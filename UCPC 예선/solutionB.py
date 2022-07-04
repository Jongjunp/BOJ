N = int(input())
line_seg = [0]*N
num_crosses = dict()
weight = dict()
coords = dict()

def ccw(x1, x2, x3, y1, y2, y3):
    check = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)
    if check<0: return -1 #cw
    if check>0: return 1 #ccw
    else: return 0

def iscross(sx1, sy1, ex1, ey1, sx2, sy2, ex2, ey2):
    if (ccw(sx1,ex1,sx2,sy1,ey1,sy2)*ccw(sx1,ex1,ex2,sy1,ey1,ey2)<=0) and (ccw(sx2,ex2,sx1,sy2,ey2,sy1)*ccw(sx2,ex2,ex1,sy2,ey2,ey1)<=0):
        return True
    else:
        return False

for i in range(N):
    info = list(map(int,input().split(" ")))
    coords[i] = info[:-1]
    weight[i] = info[-1]
    num_crosses[i] = 1
for i in range(N):
    for j in range(i+1,N):
        if (iscross(coords[i][0],coords[i][1],coords[i][2],coords[i][3],coords[j][0],coords[j][1],coords[j][2],coords[j][3])):
            num_crosses[i] += 1
            num_crosses[j] += 1

        

