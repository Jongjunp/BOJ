#include <iostream>
using namespace std;
const int LIMIT = 37;
int main() {
    int N;
    long B;
    cin >> N >> B;
    int arr[LIMIT][5][5] = {0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[0][i][j];
        }
    }
    for (int i=1; i<LIMIT; i++) {
        for (int j=0; j<N; j++){
            for (int k=0; k<N; k++) {
                int sum = 0;
                for (int l=0; l<N; l++) {
                    sum += (arr[i-1][j][l]*arr[i-1][l][k])%1000;
                    sum = sum%1000;
                }
                arr[i][j][k] = sum;
            }
        }
    }
    bool bin_arr[LIMIT] = {false};
    short digit = 0;
    while(B!=0) {
        bin_arr[digit] = B%2;
        B = B/2;
        digit += 1;
    }
    int answer[5][5] = {0};
    int temp[5][5] = {0};
    for (int i=0; i<N; i++) {
        answer[i][i] = 1;
    }
    for (int i=0; i<LIMIT; i++) {
        if (bin_arr[i]) {
            for (int j=0; j<N; j++){
                for (int k=0; k<N; k++) {
                    int sum = 0;
                    for (int l=0; l<N; l++) {
                        sum += (answer[j][l]*arr[i][l][k])%1000;
                        sum = sum%1000;
                    }
                    temp[j][k] = sum;
                }
            }
            for (int n=0; n<N; n++) {
                for (int m=0; m<N; m++) {
                    answer[n][m] = temp[n][m];
                }
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}