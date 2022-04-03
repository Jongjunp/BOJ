#include <iostream>
using namespace std;
const int MAX = 2000000;

int main(){
    int num_house;
    int houses[1000][3] = {0};
    int dp[1000][3] = {0};
    cin >> num_house;
    for (int i=0; i<num_house; i++) {
        cin >> houses[i][0] >> houses[i][1] >> houses[i][2];
    }
    int start = (num_house-1)/2;
    int left = start;
    int right = start;
    int final_answer = MAX;
    for (int h=0; h<3; h++) {
        dp[start][h] = houses[start][h];
        dp[start][(h+1)%3] = MAX;
        dp[start][(h+2)%3] = MAX;
        while (left!=0 && right!=num_house-1) {
            for (int k=0; k<3; k++) {
                if (dp[left][(k+1)%3]+houses[left-1][k] < dp[left][(k+2)%3]+houses[left-1][k]) {
                    dp[left-1][k] = dp[left][(k+1)%3]+houses[left-1][k];
                }
                else {
                    if (dp[left][(k+1)%3]==MAX && dp[left][(k+2)%3]==MAX) {
                        dp[left-1][k] = MAX;
                    }
                    else {
                        dp[left-1][k] = dp[left][(k+2)%3]+houses[left-1][k];
                    }
                }
                if (dp[right][(k+1)%3]+houses[right+1][k] < dp[right][(k+2)%3]+houses[right+1][k]) {
                    dp[right+1][k] = dp[right][(k+1)%3]+houses[right+1][k];
                }
                else {
                    if (dp[right][(k+1)%3]==MAX && dp[right][(k+2)%3]==MAX) {
                        dp[right+1][k] = MAX;
                    }
                    else {
                        dp[right+1][k] = dp[right][(k+2)%3]+houses[right+1][k];
                    }
                }
            }
            left -= 1;
            right += 1;
        }
        int answer = MAX;
        if (right!=num_house-1) {
            int last = num_house-1;
            for (int k=0; k<3; k++) {
                if (last==1) {
                    if (houses[last][k]+houses[last-1][(k+1)%3] < houses[last][k]+houses[last-1][(k+2)%3]) {
                        if (houses[last][k]+houses[last-1][(k+1)%3] < answer) {
                            answer = houses[last][k]+houses[last-1][(k+1)%3];
                        }
                    }
                    else {
                        if (houses[last][k]+houses[last-1][(k+2)%3] < answer) {
                            answer = houses[last][k]+houses[last-1][(k+2)%3];
                        }
                    }
                }
                else {
                    for (int m=1; m<=2; m++) {
                        for (int l=1; l<=2; l++) {
                            int temp = houses[last][k] + dp[left][(k+m)%3] + dp[right][(k+l)%3] - houses[start][h];
                            if (temp < answer) {
                                answer = temp;
                            }
                        }
                    }
                }
            }
        }
        else {
            for (int k=0; k<3; k++) {
                if (dp[right][k]+dp[left][(k+1)%3] < dp[right][k]+dp[left][(k+2)%3]) {
                    if (dp[right][k]+dp[left][(k+1)%3]-houses[start][h] < answer) {
                        answer = dp[right][k]+dp[left][(k+1)%3]-houses[start][h];
                    }
                }
                else {
                    if (dp[right][k]+dp[left][(k+2)%3]-houses[start][h] < answer) {
                        answer = dp[right][k]+dp[left][(k+2)%3]-houses[start][h];
                    }
                }
            }
        }
        if (answer < final_answer) {
            final_answer = answer;
        }
    }
    for (int i=0; i<num_house; i++) {
        for (int j=0; j<3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << final_answer << endl;
}