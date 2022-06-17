#include <iostream>
#include <vector>
using namespace std;
const int MAX = 32001;
vector<int> comparison[MAX];
bool visited[MAX] = {false};
vector<int> order;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int N,M,A,B;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        comparison[B].push_back(A);
    }
    for (int i=1; i<=N; i++) {
        if (comparison[i].empty() && !visited[i]) {
            order.push_back(i);
            visited[i] = true;
            
        }
    }
}