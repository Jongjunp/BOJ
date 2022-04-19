# 16946. 벽 부수고 이동하기 4

# 문제 정의
> 이 문제는 BFS를 응용하여 풀어야 하는 문제이다.

# 문제 풀이
> 우선 문제 상황을 살펴보면 맵이 주어지고 해당 맵의 벽을 허물었을 때, 해당 칸에서부터 자유롭게 이동할 수 있는 칸의 개수를 구해야 한다.
> 이 때, 각각의 벽을 중심으로 BFS를 벽의 개수만큼 반복하게되면 동일한 빈 영역에 대해 계속해서 중복해서 BFS를 수행하게 되어 시간복잡도가 과도하게 증가한다.
> 따라서, 맵의 각각의 빈공간들에 대해서 우선적으로 BFS를 수행하고 구역별로 분류한 후, 각 구역별 빈공간의 숫자를 배열에 저장해놓는다.
> 이후, 맵의 벽들에 대해서 상하좌우를 탐색해 벽이 있으면 넘어가고 빈공간이 있으면 해당 구역의 빈공간 숫자를 더해서 10으로 나눈 값으로 출력한다. 이 때, 같은 구역에 해당하는 수를 여러번 더하지 않도록 주의해야 한다.
``` cpp
short fill = cnt%10;
temp_group[group] = fill;
temp_answer[i][j] = group;
filled[i][j] = true;
queue< pair<int,int> > q2;
pair<int,int> init_loc = make_pair(i,j);
q2.push(init_loc);
while (!q2.empty()) {
    int x = q2.front().first;
    int y = q2.front().second;
    q2.pop();
    if (x>0) {
        if (field[x-1][y]!=wall && !filled[x-1][y]) {
            pair<int,int> new_loc = make_pair(x-1,y);
            q2.push(new_loc);
            filled[x-1][y] = true;
            temp_answer[x-1][y] = group;
        }
    }
    if (x<N-1) {
        if (field[x+1][y]!=wall && !filled[x+1][y]) {
            pair<int,int> new_loc = make_pair(x+1,y);
            q2.push(new_loc);
            filled[x+1][y] = true;
            temp_answer[x+1][y] = group;
        }
    }
    if (y>0) {
        if (field[x][y-1]!=wall && !filled[x][y-1]) {
            pair<int,int> new_loc = make_pair(x,y-1);
            q2.push(new_loc);
            filled[x][y-1] = true;
            temp_answer[x][y-1] = group;
        }
    }
    if (y<M-1) {
        if (field[x][y+1]!=wall && !filled[x][y+1]) {
            pair<int,int> new_loc = make_pair(x,y+1);
            q2.push(new_loc);
            filled[x][y+1] = true;
            temp_answer[x][y+1] = group;
        }
    }
}
group += 1;
```

# 주의할 점
> 중복되는 구역을 고려할 때, array를 사용해서 알고리즘을 구현하는 것보다 C++ STL set을 사용하는 것이 훨씬 효율적이다.