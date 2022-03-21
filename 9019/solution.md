# 9019. DSLR

# 문제 정의
> 이 문제는 BFS의 응용이다.
> 레지스터와 레지스터 조작 명령으로 가려져 있지만 결국 처음 주어진 숫자를 노드라고 보면 하나의 노드에서 각각의 명령(D,S,L,R)에 따른 네 가지 다른 노드로 연결되는 간선이 존재하는 그래프가 그려지고 목표 숫자, 즉 목표 노드를 검색을 통해 찾는 문제로 환원된다.

# 문제 풀이
> BFS의 구현과 마찬가지로 문제를 풀어주면 된다. 
> 이 때, 각각의 노드는 레지스터 명령에 따라 변환된 숫자와 처음 숫자에서 현재 숫자까지 도달하기 위해 행한 명령의 집합을 포함한 tuple 형태로 구성해주면 된다.
> 또한 방문한 노드와 방문하지 않은 노드를 구분하기 위해 index가 0에서 9999까지의 array를 생성해 방문 여부를 표시한다.
> list를 이용해서 구현해도 되지만 이 경우, 시간 복잡도가 O(n)이 되어 주어진 시간을 초과하게 된다.
> BFS의 주요 구현은 다음과 같다.

```
        loop {
            let tuple = visit_nodes.pop_front().unwrap();
            let walker = tuple.0 as i32;
            let mut d_way = tuple.1.clone();
            let mut s_way = tuple.1.clone();
            let mut l_way = tuple.1.clone();
            let mut r_way = tuple.1.clone();
            let d_trans = ((walker*2)%10000) as u32;
            let s_trans = ((walker-1).rem_euclid(10000)) as u32;
            let l_trans = (((walker*10)%10000)+((walker*10)/10000)) as u32;
            let r_trans = ((walker/10)+((walker%10)*1000)) as u32;
            if d_trans == dest {
                d_way.push_str("D");
                println!("{}",d_way);
                break;
            }
            if s_trans == dest {
                s_way.push_str("S");
                println!("{}",s_way);
                break;
            }
            if l_trans == dest {
                l_way.push_str("L");
                println!("{}",l_way);
                break;
            }
            if r_trans == dest {
                r_way.push_str("R");
                println!("{}",r_way);
                break;
            }
            if ref_vec[d_trans as usize] {
                d_way.push_str("D");
                visit_nodes.push_back((d_trans,d_way));
                ref_vec[d_trans as usize] = false;
            }
            if ref_vec[s_trans as usize] {
                s_way.push_str("S");
                visit_nodes.push_back((s_trans,s_way));
                ref_vec[s_trans as usize] = false;
            }
            if ref_vec[l_trans as usize] {
                l_way.push_str("L");
                visit_nodes.push_back((l_trans,l_way));
                ref_vec[l_trans as usize] = false;
            }
            if ref_vec[r_trans as usize] {
                r_way.push_str("R");
                visit_nodes.push_back((r_trans,r_way));
                ref_vec[r_trans as usize] = false;
            }
        }
```

# 주의할 점
> 시간 초과를 막기 위해서 0~9999까지의 숫자에 대해 모두 D,S,L,R 연산을 수행한 뒤의 결과가 어떤지 matrix에 미리 저장해 놓아야 한다.

