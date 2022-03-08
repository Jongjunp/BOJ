#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_LEN = 101;
    const int MAX_SIZE = 100001;
    int numObj, knapSize;
    scanf("%d %d", &numObj, &knapSize);
    int objWeight[MAX_LEN] = {0};
    int objValue[MAX_LEN] = {0};
    for (int k=1; k<=numObj; k++) {
        scanf("%d %d", &objWeight[k], &objValue[k]);
    }

    int solutionTable[MAX_LEN][MAX_SIZE] = {0};
    for (int i=0; i<=numObj; i++) {
        for (int j=0; j<=knapSize; j++) {
            if ((i==0) || (j==0)) {
                solutionTable[i][j] = 0;
            }
            else {
                if (j >= objWeight[i]) solutionTable[i][j] = max(objValue[i]+solutionTable[i-1][j-objWeight[i]], solutionTable[i-1][j]);
                else solutionTable[i][j] = solutionTable[i-1][j];
            }
        }
    }

    cout << solutionTable[numObj][knapSize] << endl;
    return 0;
}