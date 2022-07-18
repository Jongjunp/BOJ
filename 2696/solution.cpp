#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    int T, N, num;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        priority_queue<int, vector<int>, less<int> > max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        vector<int> middles;
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
            if (i%2) {
                middles.push_back(max_heap.top());
            }
        }
        printf("%d\n",(int)middles.size());
        vector<int>::iterator iter;
        int cnt = 0;
        for (iter=middles.begin(); iter!=middles.end(); iter++) {
            printf("%d ",*iter);
            cnt += 1;
            if (cnt%10==0) {
                printf("\n");
            }
        }
        printf("\n");
    }
}