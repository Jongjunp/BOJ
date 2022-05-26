# 11438. LCA2

# 문제 정의
> 이 문제는 LCA(Least Common Ancestor)를 구하는 문제이다.
> 크기가 큰 트리에 대해서 LCA를 구할 때, Sparse matrix를 이용하는 것이 중요하다.

# 문제 풀이
> LCA problem 풀이의 핵심은 두 target node u,v에 대해서 아래의 두 가지 process를 순차적으로 수행하는 것이다.
1. (WLOG, depth(u)>depth(v)) u와 v의 depth가 동일해질 때까지 u를 parent(u)로 치환한다.
2. u와 v의 depth가 동일하고, u와 v가 같지 않을 때, parent(u)와 parent(v)가 같을 때까지 u는 parent(u)로, v는 parent(v)로 치환한다.
> 이 때, 본 문제에서는 트리의 크기가 비교적 크므로, TLE를 막기 위해서 parent matrix를 이차원 배열로 설정하여 sparse matrix를 구현한다.
> parent[u][k]는 node u의 2^k 번째 parent를 의미한다.

``` cpp
        if (depth[u]<depth[v]) {
            swap(u,v);
        }
        int diff = depth[u]-depth[v];
        int p = 0;
        while (diff) {
            if (diff%2) {
                u = parent[u][p];
            }
            p += 1;
            diff /= 2;
        }
        //depth[u] becomes equal to depth[v]
        if(u != v){
            for(int j=MAX_DEPTH-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j]!=parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
```
# 주의할 점
> 바이토닉 수열이 두 방향에서 바라본 LIS의 합과 같다는 점을 최대한 활용해야 한다.

