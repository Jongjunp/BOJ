#include <iostream>
#include <string>
using namespace std;

int main() {
    int numTest;
    cin >> numTest;
    for (int i=0; i<numTest; i++) {
        int M,N,x,y;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int larger = max(M,N);
        int smaller = min(M,N);
        int fst;
        int snd;
        int res = -1;
        if (larger==M) {
            fst = x;
            snd = y;
        }
        else {
            fst = y;
            snd = x;
        }
        int LCM = larger;
        while (!((LCM%M==0) && (LCM%N==0))) {
            LCM+=larger;
        }
        for (int k = fst; k<= LCM; k+=larger) {
            if (k%smaller==snd%smaller) {
                res = k;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}