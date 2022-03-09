# 12865. 평범한 배낭

# 문제 정의
> 이 문제는 기본적인 0-1 knapsack problem이다.
> knapsack problem이란 배낭에 담을 수 있는 무게의 최대값이 주어져 있고, 해당 배낭에 담을 물건들의 무게와 가치가 매겨져 있는 상황에서 배낭에 물건을 담을 때, 배낭에 담은 물건의 가치의 합이 최대가 되도록 만드는 문제이다.
> 이 때, 물건을 쪼갤 수 있냐, 없냐에 따라서 fractional knapsack prolbem과 0-1 knapsack problem으로 분류될 수 있다.

# 문제 풀이
> 0-1 knapsack problem의 경우, Dynamic problem을 이용해서 해결할 수 있다.
배낭의 최대 수용가능 무게가 W이고, 주어진 물건의 개수가 N개일 때, 배낭에 넣을 수 있는 물건들의 가치의 합의 최댓값을 maxValue(N)(W)라고 생각해보자.
> 먼저 N 또는 W가 0인 경우를 생각해보자. 이 경우에는 배낭에 물건을 하나도 넣지 않거나 배낭에 어떤 물건도 넣을 수 없는 상황이므로 그 값을 0으로 저장해주어야 한다.
> N, W 모두 0이 아닌 경우, 다시 두 가지 경우를 생각해볼 수 있다.
> 1. N번째 물건이 배낭에 들어가야 최적의 해가 되는 경우
> 2. N번째 물건이 배낭에 들어가지 않아야 최적의 해가 되는 경우
> 각각의 경우에 있어서 그 가치는 다음과 같이 계산된다.
> 1. maxValue(N)(W) = v_N + maxValue(N-1)(W-(w_N))
> 2. maxValue(N)(W) = maxValue(N-1)(W)
> 따라서 이 두 가지 값 중 더 큰 값을 가지는 경우를 고르도록 프로그래밍 하면 된다.
''' cpp
if ((i==0) || (j==0)) {
    solutionTable[i][j] = 0;
    }
    else {
        if (j >= objWeight[i]) solutionTable[i][j] = max(objValue[i]+solutionTable[i-1][j-objWeight[i]], solutionTable[i-1][j]);
        else solutionTable[i][j] = solutionTable[i-1][j];
    }
'''

# 주의할 점
> DP를 위한 2D array를 만들 때, 입력으로 주어진 범위까지만을 table의 index로 설정해서는 안된다. 이 같은 경우, index의 끝부분인 corner case에서 에러가 일어날 수 있기 때문에 주어진 입력 값 범위 전부를 다룰 수 있는 array를 만들어야 한다.

