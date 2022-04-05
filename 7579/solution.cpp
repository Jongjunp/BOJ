#include <iostream>
using namespace std;
const int MAX = 101;
const int COSTMAX = 10001;

int main() {
    int N,M;
    cin >> N >> M;
    int memory[MAX] = {0};
    int cost[MAX] = {0};
    int solution[MAX][COSTMAX] = {0};
    for (int i=0; i<N; i++) {
        cin >> memory[i];
    }
    for (int j=0; j<N; j++) {
        cin >> cost[j];
    }
    int min_cost = COSTMAX;
    for (int i=0; i<N+1; i++) {
        for (int j=0; j<COSTMAX; j++) {
            if (i==0 || j==0) {
                solution[i][j] = 0;
            }
            else {
                if (j >= cost[i-1]) solution[i][j] = max(solution[i-1][j], solution[i-1][j-cost[i-1]]+memory[i-1]);
                else solution[i][j] = solution[i-1][j];
            }
            if (solution[i][j]>=M && j<min_cost) {
                min_cost = j;
            }
        }
    }
    cout << min_cost << endl;
}