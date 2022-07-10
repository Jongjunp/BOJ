#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;
int main() {
    int N, num;
    int temp = 0;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &num);
        if (max_heap.empty()) {
            max_heap.push(num);
        }
        else if (max_heap.size()==min_heap.size()) {
            max_heap.push(num);
        }
        else {
            min_heap.push(num);
        }

        if (((!max_heap.empty())&&(!min_heap.empty())) && (max_heap.top()>min_heap.top())) {
            int max_in_max = max_heap.top();
            int min_in_min = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(min_in_min);
            min_heap.push(max_in_max);
        }
        printf("%d\n", max_heap.top());
    }
}