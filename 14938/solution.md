# 14938. 서강그라운드

# 문제 정의
> 본 문제는 다익스트라 알고리즘을 사용해서 각각의 노드에 대해서 해당 노드에서 그래프의 다른 노드까지 도달하는데 필요한 최소 거리를 구하는 문제이다.
> 올바른 다익스트라 알고리즘의 구현이 핵심인 문제이다. 플로이드 와샬 알고리즘을 사용할 수도 있다. 다만 개인적으로 플로이드 와샬 알고리즘에서 반복문을 한 번더 거치는 것보다 하나의 노드에 대해서 다익스트라 알고리즘을 N번 돌리는 것이 더 간단하게 느껴져 다익스트라 알고리즘으로 구현하였다.

# 문제 풀이
> 다익스트라 알고리즘을 구현하기 위해서 노드의 번호와 출발 노드에서 해당 노드까지 도달하는데 필요한 거리를 저장하는 pair들로 구성된 큐를 선언하였다.
> 그리고 출발 노드에서 다른 모든 노드까지의 최소 거리를 지속적으로 업데이트 시키기 위한 배열을 선언하였다.
> 첫 번째로 출발 노드의 정보를 큐에 넣는다.
> 두 번째로 큐에 저장된 노드를 하나 꺼내온다.
> 꺼내온 노드와 연결된 모든 다른 노드들을 연결하는 간선들을 조사하여 최소 거리 배열에 저장된 거리보다 조사한 간선을 통한 거리가 더 짧다면 이를 배열에 업데이트 시키고 새롭게 조사한 노드를 큐에 넣는다.
> 이 과정을 큐에 저장된 노드가 없을 때까지 반복한 후, 최소 거리 배열에서 탐색 가능거리 안쪽에 있는 노드들을 골라내어 해당 노드들이 가지고 있는 아이템 숫자를 모두 더한다.
> 이 후, 출발 노드를 그래프 상의 다른 노드들로 한 번씩 변경해가며 최대 아이템 숫자를 찾는다.
``` cpp
    queue< pair<int,int> > region_queue;
    int path_len_list[101];
    for (int r=0; r<101; r++) {
        path_len_list[r] = INF;
    }

    path_len_list[start_region] = 0;
    region_queue.push(pair<int,int>(start_region,0));
    while (!region_queue.empty()) {
        pair<int,int> region = region_queue.front();
        for (int m=1; m <= num_region; m++) {
            if ((field_arr[region.first][m]!=0)
                 && (path_len_list[m] > (region.second+field_arr[region.first][m]))) {
                path_len_list[m] = region.second+field_arr[region.first][m];
                region_queue.push(pair<int,int>(m,region.second+field_arr[region.first][m]));
            }
        }
        region_queue.pop();
    }
```

# 주의할 점
> 탐색 거리에 대한 제한 때문에 BFS와 경계 조건을 활용하여 풀려고 생각할 수도 있지만 이 경우에는 동일 노드를 한 번 탐색하면 더이상 업데이트 시키지 않기 때문에 실제로 탐색거리 안쪽에 있으나 이를 파악하지 못하는 경우가 발생할 수 있다. 따라서 다익스트라 알고리즘이나 플로이드 와샬 알고리즘과 같은 최단 경로 탐색 알고리즘을 활용해주어야 한다.