def main():
    inputSize = list(map(int, input().split(' ')))
    height = inputSize[0]
    width = inputSize[1]
    inputMat = []
    numWayMat = [[0]*width for _ in range(height)]
    for i in range(height):
        rowList = list(map(int, input().split(' ')))
        inputMat.append(rowList)
    for i in range(height):
        for j in range(width):
            numWayMat[i][j]