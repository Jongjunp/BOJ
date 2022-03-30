# 12852. 1로 만들기 2

# 문제 정의
> 이 문제는 BFS 알고리즘과 2차원 배열 구조를 이용해 풀 수 있는 탐색 문제이다.
> 9019번 DSLR 문제와 마찬가지로 각각의 숫자를 노드로 보고 BFS 알고리즘을 떠올려 주면 된다.

# 문제 풀이
> 큐 자료구조와 2차원 배열을 이용해 BFS를 구현하면 된다.
> 핵심적인 BFS 구현은 다음과 같다.
''' cpp
    while (walker!=1) {
        int div3 = res_mat[walker][0];
        int div2 = res_mat[walker][1];
        int sub1 = res_mat[walker][2];
        if ((div3!=0)&&(!visited[div3])) {
            q.push(pairs(div3, q.front().second+" "+to_string(div3)));
            visited[div3] = true;
        }
        if ((div2!=0)&&(!visited[div2])) {
            q.push(pairs(div2, q.front().second+" "+to_string(div2)));
            visited[div2] = true;
        }
        if ((sub1!=0)&&(!visited[sub1])) {
            q.push(pairs(sub1, q.front().second+" "+to_string(sub1)));
            visited[sub1] = true;
        }
        q.pop();
        walker = q.front().first;
    }
'''

# 주의할 점
> BFS를 위한 2D array를 만들 때, 입력으로 주어진 범위까지만을 table의 index로 설정해서는 안된다. 이 같은 경우, index의 끝부분인 corner case에서 에러가 일어날 수 있기 때문에 주어진 입력 값 범위 전부를 다룰 수 있는 array를 만들어야 한다.
> 본 문제의 경우에는 입력 값의 범위가 1에서 100,000까지로 크기가 커서 스택 영역에서 다루면 오버플로우가 발생한다. 따라서 동적 메모리 할당을 통해 구현해주어야 한다.

