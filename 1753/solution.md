# 1753. 최단경로

# 문제 정의
> 이 문제는 다익스트라 알고리즘을 이용해서 푸는 문제이다.
> 단, 주어지는 정점의 개수가 최대 20000개이기 때문에 이중 배열을 이용하게 되면 메모리 공간(stack 영역)이 부족해지게 된다.
> 따라서, 우선순위 큐 자료구조를 이용해서 구현하였다.

# 문제 풀이
> 우선, 두 가지 배열을 선언해야 한다.
> 출발 정점에서부터의 거리를 나타내는 path 배열과, 한 정점과 연결된 다른 정점들과 그 거리를 나타내는 graph 배열을 선언한다.
> 거리를 나타내는 배열에서 출발 정점을 제외한 다른 정점들의 값을 무한대 값으로 초기화하고 출발 정점의 값은 0으로 초기화한다.
> E개의 input에 대해서 각각의 정점과 그 정점과 연결된 다른 정점들까지의 거리를 저장한다.
> 이후, 한 정점과 출발 정점에서 해당 정점까지의 거리를 담은 pair를 우선순위 큐에 넣는다. 이 때, C++ container에서 구현된 우선순위 큐의 경우, 내부적으로 내림차순으로 정렬되기 때문에 거리를 음수로 넣어줘야 한다. 이는 다익스트라 알고리즘에서 정점들을 순회할 때, 거리가 가장 가까운 정점부터 먼저 순회하기 때문이다. 처음에는 출발 정점과 0을 넣게 된다.
> 우선순위 큐가 빌 때까지 각각의 정점을 순회한다. 해당 정점(편의상 P라고 하자)과 연결된 다른 정점들(편의상 p_i라고 하자.)과의 거리를 graph 배열에서 조회하면서 path 배열에 저장된 p_i 정점까지의 거리보다 P까지의 거리와 P에서 p_i까지의 거리의 합이 더 작을 때, path 배열의 값을 갱신시키고 해당 정점을 우선순위 큐에 추가한다.
> 아래는 우선순위 큐를 이용해 정점을 순회하는 것을 구현한 C++ 코드이다.
``` cpp
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        vector< pair<short,short> >::iterator iter = graph[node].begin();
        for (; iter!=graph[node].end(); iter++) {
            short next_node = iter -> first;
            short weight = iter -> second;
            if (path[next_node]>cost+weight) {
                path[next_node] = cost+weight;
                pq.push(make_pair(-path[next_node],next_node));
            }
        }
    }
```

# 주의할 점
> 빠른 입출력을 위해서 cin.tie(NULL)과 cout.tie(NULL)을 사용한다.