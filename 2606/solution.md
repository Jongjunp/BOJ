# 2606. 바이러스

# 문제 정의
> 이 문제는 BFS를 이용한 간단한 탐색 문제이다.
> 첫 번째 노드(컴퓨터)부터 시작해서 BFS를 적용시켜 주면 쉽게 풀린다.

# 문제 풀이
> Queue와 list 구조를 이용하여 BFS를 구현할 수 있다.
> Queue에 탐색할 노드를 계속해서 추가하고 visited list를 만들어 이미 방문했던 노드를 다시 방문하지 않도록 한다.
> BFS의 주요 구현은 다음과 같다.
``` cpp
    while (!q.empty()) {
        for (int j=0; j<numComp; j++) {
            if (connected[q.front()][j] && !visited[q.front()]) {
                q.push(j);
            }
        }
        visited[q.front()] = true;
        q.pop();
    }
```

# 주의할 점
> .

