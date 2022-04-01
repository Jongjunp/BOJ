# 11054. 가장 긴 바이토닉 부분 수열

# 문제 정의
> 이 문제는 LIS(Longest Increasing Subsequence)를 구하고 이를 응용하는 방식의 문제이다.
> LIS를 구할 때와 같은 방식을 적용하되 바이토닉 수열을 위한 기준을 적용하는 것이 핵심이다.

# 문제 풀이
> LIS problem의 경우, 문제 풀이의 핵심은 다음과 같다.
> 주어진 배열의 $i$ 번째 원소에 대해서 해당 원소가 임의의 증가 부분 수열의 가장 큰 수가 될 수 있는 수열을 찾아 그 수열의 길이를 저장하는 것이다.
> 이 문제 풀이 방식은 바이토닉 수열을 찾는 과정에서도 그대로 옮겨 올 수 있다. 바이토닉 수열은 순증가, 순감소 그리고 한 번의 증가와 감소가 일어나는 수열을 허용한다. 따라서 우리는 주어진 배열의 $i$ 번째 원소에 대해서 해당 원소가 바이토닉 부분 수열의 가장 큰 수가 될 수 있는 수열을 찾아 그 수열의 길이를 저장하는 것이다.
> 주어진 수열의 각각의 원소마다 그 원소를 최대값으로 삼는 바이토닉 수열의 길이는 LIS의 정의에 따라 구할 수 있다.
> LIS problem을 풀 때, 어떤 원소를 최댓값으로 하는 LIS의 길이를 구하였다. 바이토닉 수열의 경우, 수열의 첫 번째 원소부터 진행해서 구한 LIS의 길이와 수열의 마지막 원소부터 진행해서 구한 LIS의 길이를 합한 것에서 중복되는 원소 하나를 빼서 구할 수 있다.
> 따라서 LIS를 구하는 과정을 두 번 진행한 뒤, 나온 수열의 elementwise sum을 구하고 결과 수열의 최댓값을 선택하면 된다.

``` rust
given_list.reverse();
    for ele in given_list.iter() {
        if lds_list.is_empty() || ele > lds_list[lds_list.len()-1] {
            lds_list.push(ele);
            lds_num_list.push(lds_list.len());
            continue;
        }
        let mut lds_left = 0;
        let mut lds_right = lds_list.len()-1;
        let mut lds_mid = (lds_left+lds_right)/2;
        while lds_right > lds_left {
            if ele <= lds_list[lds_mid] {
                lds_right = lds_mid
            }
            else {
                lds_left = lds_mid + 1
            }
            lds_mid = (lds_left+lds_right)/2;
        }
        lds_list[lds_mid] = ele;
        lds_num_list.push(lds_list.len());
    }
    lds_num_list.reverse();
```
# 주의할 점
> 바이토닉 수열이 두 방향에서 바라본 LIS의 합과 같다는 점을 최대한 활용해야 한다.

