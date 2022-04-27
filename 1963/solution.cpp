#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int T, X, Y, answer;
bool primes[10000] = {false};
int digit[4] = {1,10,100,1000};
void init_primes() {
    for (int i=2; i<10000; i++) {
        primes[i] = true;
    }
    for (int i=2; i*i<10000; i++) {
        if (primes[i]) {
            for (int j=2; i*j<10000; j++) {
                primes[i*j] = false;
            }
        }
    }
}
int BFS(int A, int B) {
    queue< pair<int,int> > q;
    q.push(make_pair(A,0));
    int new_num;
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        if (num==B) {
            return cnt;
        }
        q.pop();
        for (int n=0; n<4; n++) {
            for (int m=0; m<10; m++) {
                if (n==3 && m==0) {
                    continue;
                }
                new_num = num-(((num/digit[n])%10)*digit[n])+(m*digit[n]);
                if (new_num==B) {
                    return cnt+1;
                }
                else if (primes[new_num]) {
                    primes[new_num] = false;
                    q.push(make_pair(new_num,cnt+1));
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i=0; i<T; i++) {
        init_primes();
        cin >> X >> Y;
        answer = BFS(X,Y);
        if (answer==-1) {
            cout << "Impossible" << endl;
        }
        else {
            cout << answer << endl;
        }
    }
}