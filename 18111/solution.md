# 18111. 마인크래프트

# 문제 정의
> 본 문제는 브루트포스 알고리즘과 이분탐색 알고리즘을 적절히 혼합해야 하는 문제이다.

# 문제 풀이
> 집터를 평평하게 만들 때, 그 기준 높이를 가장 낮은 높이에서 가장 높은 높이까지 올려가며 탐색을 진행한다고 가정하자.
> 이 때, 임의의 높이 k에 대해서 k를 기준으로 평평하게 만들 때에 필요한 시간과 k-1을 기준으로 평평하게 만들 때 필요한 시간의 차이는 단조증가의 양상을 띠게 된다. 이는 블록을 공중에 띄우도록 쌓거나 캐낼 수 없기 때문이다.
> 가장 낮은 높이를 기준으로 할 때, 시간의 차이는 항상 음수가 된다. 따라서 높이가 올라감에 따라 가장 낮은 높이와 가장 높은 높이 사이에 시간의 차이가 음수에서 양수로 바뀌는 지점이 생길 수 있다.
> 또한 인벤토리의 블록 개수와 캐낼 수 있는 블록 개수의 제한으로 인해 특정 높이 이상으로는 평평하게 만들 수 없다.
> 우리가 찾아야 할 것은 시간 차가 음수인 동시에 블록 개수 제한 조건을 충족하는 최대 높이이다. 위에서 이 조건들이 한 가지 방향성을 가진다는 것을 보였기 때문에 이분탐색 알고리즘을 적용해 해당 높이를 찾아낼 수 있다. 
> 최종적으로 우리가 찾은 높이를 기준으로 집터를 평평하게 만들 때 걸리는 시간을 구하면 된다.
> 이 경우, 시간 복잡도가 O(N^2*log(H))가 되어서 문제의 시간제한에 걸리지 않게 된다.

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
> 이분 탐색을 적용해야 한다.