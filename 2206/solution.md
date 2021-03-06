# 2206. 벽 부수고 이동하기

# 문제 정의
> 이 문제는 BFS를 이용하여 풀 수 있는 문제이다.
> 단, 최대 한 번까지 벽을 부술 수 있다는 조건으로 인해 BFS를 수행하면서 이미 방문한 노드를 체크하는 과정에서 벽을 부수고 이동하였는지, 아닌지 확인하기 위해서 3차원 배열을 활용해야 한다.

# 문제 풀이
> 우선 BFS를 구현하기 위한 노드의 자료구조를 정해야 한다. 
> 본 문제를 주어진 시간 내에 풀기 위해서 노드의 자료구조는 최대한 단순해야 한다.
> 여기서는 현재 방문한 좌표값과 시작점으로부터의 거리, 그리고 벽을 부순 횟수(최대 1회)를 설정하였다.
> 그리고 방문한 노드를 담기 위한 배열을 선언하였다.
> 이 때, 이 배열의 의미를 잘 설정하는 것이 중요하다. 
> 본 문제에서 목적지까지의 최단 거리를 찾기 위해서 이동할 때, 이동하는 경로는 크게 두 가지로 나눌 수 있다.
> 첫 번째는 벽을 부수지 않고 이동하는 경우이고, 두 번째는 벽을 한 번 부수고 이동하는 경로이다.
> 이 두가지 경우를 동시에 고려하면 BFS 탐색 중, 벽을 부수지 않고 이동하는 경로에서 방문하지 않은 노드를
벽을 부수고 이동한 경로에서 미리 방문하여, 벽을 부수지 않고 이동하는 경로에서 해당노드를 방문하지 못하는 일이 발생할 수 있다.
> 따라서 이를 막기 위해서 방문한 노드를 담는 배열을 분리할 필요가 있고, 이를 위해서 3차원 배열을 설정하였다. 
> 이 3차원 배열을 visited라고 할 때, 이 배열의 차원은 1000*1000*2가 되고, 
벽을 부순 횟수에 따라서 (i,j) 노드의 방문 여부를 visited[i][j][0] 또는 visited[i][j][1]에 저장한다.
> 추가적으로 실행 시간 최적화를 위해서 왼쪽이나 위쪽으로 이동하는 경우를 최대한 제한하였다.

```cpp
    if (w!=width-1) {
        if ((h==height-1) && (w+1==width-1)) {
            min_action_num = dist+1;
            reachable = true;
            break;
        }
        else {
            if ((breaked==0) && (board[h][w+1]==block)) {
                visited[h][w+1][breaked+1] = true;
                pair< pair<int,int>, pair<int,int> > right_state = make_pair(make_pair(h,w+1), make_pair(dist+1, breaked+1));
                state_queue.push(right_state);
            }
            else if ((board[h][w+1]==blank) && (!visited[h][w+1][breaked])) {
                visited[h][w+1][breaked] = true;
                pair< pair<int,int>, pair<int,int> > right_state = make_pair(make_pair(h,w+1), make_pair(dist+1, breaked));
                state_queue.push(right_state);
            }
        }
    }
```

# 주의할 점
> 방문한 노드를 확인하기 위한 배열이나 리스트를 노드의 구성요소로 이용하게 되면 메모리 할당과 해제에 이용되는 시간이 증가하게 되고, 주어진 시간 내에 문제를 해결할 수 없다. 따라서 3차원 배열을 이용해 방문한 노드를 확인한다는 아이디어를 먼저 떠올리는 것이 중요하다.