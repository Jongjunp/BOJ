# 2206. 벽 부수고 이동하기

# 문제 정의
> 이 문제는 BFS를 이용하여 풀 수 있는 문제이다.
> 단, 최대 한 번까지 벽을 부술 수 있다는 조건으로 인해 BFS를 수행하면서 이미 방문한 노드를 체크하는 과정에서 벽을 부수고 이동하였는지, 아닌지 확인하기 위해서 3차원 배열을 활용해야 한다.

# 문제 풀이
> 

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
> 