# 6549. 히스토그램에서 가장 큰 직사각형

# 문제 정의
> 이 문제는 주어진 히스토그램에서 가장 큰 직사각형을 찾는 문제이다.
> 세그먼트 트리를 이용해서 주어진 문제를 풀 수 있다.

# 문제 풀이
> 본 문제는 기존의 임의 구간의 합을 구하는 세그먼트 트리 구조를 변형시켜 해결할 수 있다.
> 히스토그램의 임의의 구간에서 그 구간 전체에 걸쳐있는 직사각형의 넓이는 그 구간에서 가장 낮은 높이에 의해 결정된다.
> 따라서 임의의 구간에 대한 직사각형의 최대 넓이는 다음 세 가지 넓이 중 가장 큰 값을 선택하면 된다. (가장 낮은 높이를 갖는 히스토그램 막대의 index를 i라 하자.)
1. 그 구간 전체에 걸쳐있는 직사각형의 넓이
2. [i+1, end] 구간에서의 최대 직사각형 넓이
3. [start, i] 구간에서의 최대 직사각형 넓이
> 이를 O(NlogN) 안에 구하기 위해서 세그먼트 트리 구조를 이용한다.
> 아래 코드에 나와 있듯이, init() 함수를 재귀적으로 정의하여 주어진 구간에서 최소 높이를 갖는 index 값을 저장하는 세그먼트 트리 구조를 만들고, query() 함수를 이용하여 임의의 구간에서 가장 낮은 높이를 갖는 index 값을 재귀적으로 구할 수 있다. 그 후에는 sum() 함수를 이용하여 위에서 설명했듯이 직사각형의 최대 넓이를 계산하면 된다.
``` cpp
void init(int start, int end, int node) {
    if (start==end) {
        seg_tree[node] = start;
    }
    else {
        int mid = (start+end)/2;
        init(start,mid,2*node);
        init(mid+1,end,2*node+1);
        if (histogram[seg_tree[2*node]]<histogram[seg_tree[2*node+1]]){
            seg_tree[node]=seg_tree[2*node];
        }
        else {
            seg_tree[node]=seg_tree[2*node+1];
        }
    }
}
long long query(int start, int end, int node, int left,  int right) {
    if (left>end || start>right) {
        return -1;
    }
    if (left<=start && end<=right) {
        return seg_tree[node];
    }
    int mid = (start+end)/2;
    long long idx1 = query(start,mid,2*node,left,right);
    long long idx2 = query(mid+1,end,2*node+1,left,right);
    if (idx1==-1) {
        return idx2;
    }
    if (idx2==-1) {
        return idx1;
    }
    if (histogram[idx1]<histogram[idx2]) {
        return idx1;
    }
    else {
        return idx2;
    }
}
long long sum(int start, int end) {
    long long idx = query(0,n-1,1,start,end);
    long long max_area = histogram[idx]*(end-start+1);
    if (start<=idx-1) {
        long long area = sum(start,idx-1);
        if (max_area<area) {
            max_area = area;
        }
    }
    if (idx+1<=end) {
        long long area = sum(idx+1,end);
        if (max_area<area) {
            max_area = area;
        }
    }
    return max_area;
}
```

# 주의할 점
> 세그먼트 트리라는 자료구조에 대한 이해를 바탕으로 응용력을 기르자.