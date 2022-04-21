#include <iostream>
using namespace std;
const int INIT = -1;
int main() {
    int n = INIT;
    bool primes[250000] = {true};
    for (int i=2; i<250000; i++) {
        primes[i] = true;
    }
    for (int i=2; i*i<250000; i++) {
        if (primes[i]) {
            for (int j=2; i*j<250000; j++) {
                primes[i*j] = false;
            }
        }
    }
    while(n!=0) {
        cin >> n;
        if (n==0) {
            break;
        }
        int cnt = 0;
        for (int i=n+1; i<=2*n; i++) {
            if (primes[i]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}