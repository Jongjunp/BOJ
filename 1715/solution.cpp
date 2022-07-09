#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main() {
    int N,size,set1,set2,new_set,answer;
    answer = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> size;
        pq.push(-size);
    }
    while (!pq.empty()) {
        set1 = -pq.top();
        pq.pop();
        if (pq.empty()) {
            break;
        }
        set2 = -pq.top();
        pq.pop();
        new_set = set1+set2;
        answer += new_set;
        pq.push(-new_set);
    }
    cout << answer << endl;
}