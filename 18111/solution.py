verticalSize, horizontalSize, blocksInInventory = list(map(int, input().split(' ')))
heightMap = []

for _i in range(verticalSize):
    heightMap = heightMap + list(map(int, input().split(' ')))

maxHeight = max(heightMap)
minHeight = min(heightMap)

optHeight = 0

def optCheck(height):
    remainingBlocks = blocksInInventory
    costChange = 0
    for block in heightMap:
        if (block-height < 0):
            costChange = costChange + 1
            remainingBlocks = remainingBlocks - abs(block-height)
        else:
            costChange = costChange - 2
            remainingBlocks = remainingBlocks + abs(block-height)
    return ((remainingBlocks >= 0) and (costChange <= 0))

heightList = range(minHeight, maxHeight+1)
left = 0
right = len(heightList)-1
mid = int((left+right)/2)
while (right>left+1):
    checked = optCheck(heightList[mid])
    if checked:
        left = mid
    else:
        right = mid
    mid = int((left+right)/2)
if optCheck(heightList[right]):
    optHeight = heightList[right]
else:
    optHeight = heightList[left]

optCost = 0
for block in heightMap:
    if (block-optHeight <= 0):
        optCost = optCost + abs(block-optHeight)
    else:
        optCost = optCost + (2*abs(block-optHeight))

print(str(optCost)+" "+str(optHeight))