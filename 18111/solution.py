verticalSize, horizontalSize, blocksInInventory = list(map(int, input().split(' ')))
heightMap = []
maxHeight = 0
minHeight = 256

for _i in range(verticalSize):
    heightInRow = list(map(int, input().split(' ')))
    if (maxHeight < max(heightInRow)):
        maxHeight = max(heightInRow)
    if (minHeight > min(heightInRow)):
        minHeight = min(heightInRow)
    heightMap.append(heightInRow)


for height in range(minHeight, maxHeight+1):
    remainingBlocks = blocksInInventory
    cost = 0
    for row in heightMap:
        for block in row:
            if (block-height <= 0):
                cost = cost + abs(block-height)
                remainingBlocks = remainingBlocks - abs(block-height)
            else:
                cost = cost + (2*abs(block-height))
                remainingBlocks = remainingBlocks + abs(block-height)
    if (remainingBlocks < 0):
        continue
    else:
        if (cost < optCost):
            optCost = cost
            optHeight = height

print(str(optCost)+" "+str(optHeight))