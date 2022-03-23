 # 1629. 곱셈

# 문제 정의
> 이 문제는 일반적인 DP의 2차원 배열로의 확장이라고 볼 수 있다.
> 문제 조건에서 서로 이웃한 집들 간에는 다른 페인트를 칠해야 한다는 것과 R,G,B 각각의 색을 칠하는데 필요한 비용이 주어져 있다는 것에서 2차원 DP로 정의하는 힌트를 얻을 수 있다.

# 문제 풀이
> m번째 집을 색칠하는 경우를 생각해보자.($1<=m<=N$) 집을 R,G,B 색깔로 칠한다고 가정할 때, 각각의 경우에 대해서 최소 비용으로 칠할 수 있는 경우의 수가 두 가지가 생긴다.
> m번째 집을 R로 칠할 경우, m-1번째 집을 G로 칠하는 최소 비용 경우 또는 B로 칠하는 최소 비용 경우 두 가지의 경우 중 한 가지가 m번째 집을 R로 칠하는 최소 비용 경우가 된다. 따라서 이 두 가지 비용을 비교해서 더 작은 값을 2차원 배열 인덱스에 적용하면 된다.
> 나머지 집들에 대해서도 마찬가지로 구현이 가능하다. 2차원 DP의 핵심 아이디어에 대한 구현은 아래 코드에 나와있다.
''' rust
    for j in 1..num_house {
        let cand_vec_0 = vec![cost_mat[(j-1) as usize][1]+rgb_mat[j as usize][0],cost_mat[(j-1) as usize][2]+rgb_mat[j as usize][0]];
        let cand_0 = cand_vec_0.iter().min().unwrap();
        let cand_vec_1 = vec![cost_mat[(j-1) as usize][0]+rgb_mat[j as usize][1],cost_mat[(j-1) as usize][2]+rgb_mat[j as usize][1]];
        let cand_1 = cand_vec_1.iter().min().unwrap();
        let cand_vec_2 = vec![cost_mat[(j-1) as usize][0]+rgb_mat[j as usize][2],cost_mat[(j-1) as usize][1]+rgb_mat[j as usize][2]];
        let cand_2 = cand_vec_2.iter().min().unwrap();
        let opt_ans = vec![*cand_0, *cand_1, *cand_2];
        cost_mat.push(opt_ans);
    }
'''

# 주의할 점
> Rust를 이용할 때, vector를 매크로로 생성 시, .iter() method를 적용하기 이전에 메모리 할당이 풀려서 적용이 안되는 현상이 발생하였다. ownership 관련 문제인 것 같은데 Rust manual 부분을 조금 더 읽어보아야 할 듯 하다.