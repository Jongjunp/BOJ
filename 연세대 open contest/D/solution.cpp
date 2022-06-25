#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>
using namespace std;
const int empty = 0;
const int pillar = 1;
const int bench = 2;
const int mannequin = 3;
const int start = 4;
const int forbidden = 5;
const int MAX = 2000;
int dept_store[MAX][MAX];
bool visited[MAX][MAX] = {false};

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main() {
    init();
    int M,N,K,mannequin_num;
    int health = 0;
    int min_health_spend = 0;
    cin >> N >> M >> K;
    queue< pair< pair<int,int>,int > > siru_q;
    for (int n=0; n<N; n++) {
        for (int m=0; m<M; m++) {
            int state;
            cin >> state;
            if (dept_store[n][m]==forbidden) {
                continue;
            }
            if (state==mannequin) {
                for (int a=-K; a<=K; a++) {
                    for (int b=abs(a)-K; b<=K-abs(a); b++) {
                        if (m+a<M && m+a>=0 && n+b<N && n+b>=0) {
                            if (dept_store[n+b][m+a]!=mannequin && dept_store[n+b][m+a]!=bench) {
                                dept_store[n+b][m+a] = forbidden;
                            }
                        }
                    }
                }
            }
            if (state==start) {
                pair<int,int> pair1 = make_pair(n,m);
                pair< pair<int,int>,int > pair2 = make_pair(pair1, health);
                siru_q.push(pair2);
                visited[n][m] = true;
            }
            dept_store[n][m] = state;
        }
    }
    //BFS
    while (!siru_q.empty()){
        int n = siru_q.front().first.first;
        int m = siru_q.front().first.second;
        int h = siru_q.front().second;
        siru_q.pop();
        if (m<M-1) {
            if (!visited[n][m+1] && dept_store[n][m+1]!=pillar && dept_store[n][m+1]!=mannequin && dept_store[n][m+1]!=forbidden) {
                if (dept_store[n][m+1]==bench) {
                    min_health_spend = h+1;
                    break;
                }
                pair<int,int> coord = make_pair(n,m+1);
                pair< pair<int,int>, int> state = make_pair(coord,h+1);
                siru_q.push(state);
                visited[n][m+1] = true;
            }
        }
        if (m>0) {
            if (!visited[n][m-1] && dept_store[n][m-1]!=pillar && dept_store[n][m-1]!=mannequin && dept_store[n][m-1]!=forbidden) {
                if (dept_store[n][m-1]==bench) {
                    min_health_spend = h+1;
                    break;
                }
                pair<int,int> coord = make_pair(n,m-1);
                pair< pair<int,int>, int> state = make_pair(coord,h+1);
                siru_q.push(state);
                visited[n][m-1] = true;
            }
        }
        if (n<N-1) {
            if (!visited[n+1][m] && dept_store[n+1][m]!=pillar && dept_store[n+1][m]!=mannequin && dept_store[n+1][m]!=forbidden) {
                if (dept_store[n+1][m]==bench) {
                    min_health_spend = h+1;
                    break;
                }
                pair<int,int> coord = make_pair(n+1,m);
                pair< pair<int,int>, int> state = make_pair(coord,h+1);
                siru_q.push(state);
                visited[n+1][m] = true;
            }            
        }
        if (n>0) {
            if (!visited[n-1][m] && dept_store[n-1][m]!=pillar && dept_store[n-1][m]!=mannequin && dept_store[n-1][m]!=forbidden) {
                if (dept_store[n-1][m]==bench) {
                    min_health_spend = h+1;
                    break;
                }
                pair<int,int> coord = make_pair(n-1,m);
                pair< pair<int,int>, int> state = make_pair(coord,h+1);
                siru_q.push(state);
                visited[n-1][m] = true;
            }            
        }
    }
    if (min_health_spend==0) {
        cout << -1 << endl;
    }
    else {
        cout << min_health_spend << endl;
    }
}