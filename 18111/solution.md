# 18111. 마인크래프트

# 문제 정의
> 브루트포스 알고리즘과 이분탐색 알고리즘을 적절히 혼합해야 하는 문제이다.
>

# 문제 풀이
> 
``` python
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
```

# 주의할 점
> 