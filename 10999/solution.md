# 10999. 구간 합 구하기 2

# 문제 정의
> 이 문제는 segment tree 자료구조를 이용해서 푸는 문제이다.
> 변경이 일어나는 횟수가 최대 10000번으로 비교적 크고 실행 시간이 2초이내여야 하기 때문에 lazy propagation을 이용해야 한다.

# 문제 풀이
> segment tree problem의 경우, segment tree라는 자료구조와 자료구조와 관련된 쿼리를 정확히 구현하는 것이 중요하다.
> 첫 번째 query는 segment tree를 초기화하는 것으로, 재귀적으로 segment tree의 값들을 배열의 적절한 index에 저장한다. 이 때, segment tree의 index는 1부터 시작하고 [0,mid] 범위에 해당하는 값들의 합을 아래 왼쪽 노드에, (2*n번 노드) [mid+1,end]범위에 해당하는 값들의 합을 아래 오른쪽 노드에(2*(n+1)번 노드) 각각 저장한다.
> 두 번째 query는 segment tree의 노드를 업데이트하는 것으로, 첫 번째 쿼리와 마찬가지로 재귀적으로 segment tree의 값들을 업데이트한다. 어떤 특정 원소의 값이나 어떤 범위의 원소들의 값이 변했을 때 ,이 원소들이 포함된 노드들의 값들을 모두 업데이트 시켜주어야 한다. 하지만 그렇게 되면 시간복잡도가 요구되는 값을 초과하게 된다. 따라서 시간복잡도를 최적화하기 위해서 lazy propagation을 이용해야 한다. lazy propagation의 경우, 노드의 범위가 업데이트 구간의 범위에 걸쳐있을 때는 재귀적으로 노드를 방문한다. 노드의 범위와 업데이트 구간의 범위가 겹치지 않을 때는 탐색을 중단한다. 노드의 범위가 업데이트 범위내에 속하는 노드를 방문했을 때는 해당 노드의 값을 업데이트 해주는 대신에 그 아래 노드의 값들까지 업데이트를 시키지 않고 업데이트 할 값들을 lazy tree 구조에 저장시켜 놓는다. 그리고 값들이 필요할 때 propagation을 통해 업데이트를 시켜준다.
> 세 번째 query는 주어진 범위의 구간 합을 구하는 것이다. 여기서도 propagation을 해주어야 한다는 점을 제외하고는 기존의 segment tree의 쿼리의 실행과 동일하다.

```cpp
void propagateTree(int index, int start, int end) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index] * (end-start+1);
		if (start != end) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
}

void updateTree(int index, int start, int end, long long val, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		lazy[index] += val;
        propagateTree(index, start, end);
        return;
	}
	int mid = (start + end) / 2;
	updateTree(index * 2, start, mid, val, left, right);
	updateTree(index * 2 + 1, mid + 1, end, val, left, right);
    tree[index] = tree[index*2] + tree[index*2+1];
    return;
}
```
# 주의할 점
> propagation이 언제 일어나야할지에 주의한다.

