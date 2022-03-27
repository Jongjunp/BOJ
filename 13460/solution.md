# 13460. 구슬탈출2

# 문제 정의
> 본 문제는 구슬의 움직임을 조건에 맞게 구현하고, 이를 기반으로 보드에서 구슬의 위치 상태가 어떻게 변화할 수 있는지를 BFS를 이용해 탐색하는 문제이다.
> 구슬의 움직임을 조건에 맞게 구현하는 것과 구슬의 위치 상태를 표현하는 노드를 구현하는 것이 관건이다.

# 문제 풀이
> 우선 문제의 조건에 따르면 빨간 구슬과 파란 구슬은 보드를 기울이는 방향에 따라 동시에 움직인다. 이 때, 장애물을 만나면 멈춰서고 빨간 구슬과 파란 구슬은 겹치지 않는다. 빨간 구슬만 구멍에 들어가도록 했을 때, 게임에 승리한다.
> 따라서 우선 보드의 상태를 2차원 배열로 입력받은 후, 빨간 구슬과 파란 구슬의 좌표정보만을 저장하고 빨간 구슬과 파란 구슬을 나타내는 보드의 R,B 부분을 공백 칸('.')으로 바꾼다.
> 빨간 구슬과 파란 구슬의 보드 상의 위치를 상태라고 할 때, 처음 상태에서 보드를 왼쪽으로 기울였을 때, 오른쪽으로 기울였을 때, 위로 기울였을 때, 아래로 기울였을 때에 따라 네 가지 다른 상태로 변화하게 된다. 보드의 상태(빨간 구슬과 파란 구슬의 위치 정보)를 노드로 보게 되면 전체 경우의 수가 하나의 그래프를 형성하게 된다.
> 따라서 해당 그래프 상에서 게임의 승리 조건을 달성하는 동시에 게임의 제약조건을 만족시키는 최소 깊이를 가진 노드(상태)를 BFS를 통해 찾으면 된다.
> 아래는 왼쪽으로 보드를 기울였을 때, 구슬들의 움직임을 구현하는 코드의 일부분이다.
``` cpp
    int red_result = red_w;
    int blue_result = blue_w;
    if (red_h == blue_h) {
        if (red_w < blue_w) {
            while (arr[red_h][red_result-1]==blank) {
                red_result -= 1;
            }
            if (arr[red_h][red_result-1]==hole) {
                red_result -= 1;
            }
            while ((arr[blue_h][blue_result-1]==blank) && (blue_result-1 != red_result)) {
                blue_result -= 1;
            }
            if (arr[blue_h][blue_result-1]==hole) {
                blue_result -= 1;
            }
        }
        else {
            while (arr[blue_h][blue_result-1]==blank) {
                blue_result -= 1;
            }
            if (arr[blue_h][blue_result-1]==hole) {
                blue_result -= 1;
            }
            while ((arr[red_h][red_result-1]==blank) && (red_result-1 != blue_result)) {
                red_result -= 1;
            }
            if (arr[red_h][red_result-1]==hole) {
                red_result -= 1;
            }
        }
    }
    else {
        while (arr[red_h][red_result-1]==blank) {
            red_result -= 1;
        }
        if (arr[red_h][red_result-1]==hole) {
            red_result -= 1;
        }
        while (arr[blue_h][blue_result-1]==blank) {
            blue_result -= 1;
        }
        if (arr[blue_h][blue_result-1]==hole) {
            blue_result -= 1;
        }
    }
```

> 아래는 BFS를 구현하는 코드의 일부분이다.
``` cpp
    queue< pair < pair< pair<int,int>,pair<int,int> >,int > > state_queue;
    pair< pair<int,int>,pair<int,int> > init_coords = make_pair(ori_red_coor,ori_blue_coor);
    pair < pair< pair<int,int>,pair<int,int> >,int > init_state = make_pair(init_coords,0);
    int min_action_num = INF;
    state_queue.push(init_state);
    while (!state_queue.empty()) {
        pair < pair< pair<int,int>,pair<int,int> >,int > state = state_queue.front();
        pair< pair<int,int>,pair<int,int> > coords = state.first;
        int current_action_num = state.second;
        state_queue.pop();
        if (current_action_num > 10) {
            continue;
        }
```

# 주의할 점
> 상하좌우 이동에 따른 구슬의 좌표변화에 주의해야 한다.
> 또한 Queue를 탐색하면서 빨간색 구슬이 구멍에 들어가고 파란색 구슬이 구멍에 들어가지 않았을 때, 게임이 성공적으로 끝나게 되므로 해당 경우를 만났을 때, while loop를 나오도록 해야 실행시간이 줄어들게 된다.