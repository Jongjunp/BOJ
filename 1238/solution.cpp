#include <iostream>
#include <string>
#include <queue>
#define pairs pair<int,int>
using namespace std;

const INF = 1000;
int main() {
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);
    int dist[N][N] = {MAX};
    //Create graph
    for (int i=0; i<M; i++) {
        int src, dest, time;
        scanf("%d %d %d", &src, &dest, &time);
        dist[src-1][dest-1] = time;
    }
    //1. Time to go - A* algorithm
    int minPathToGo[N] = {MAX};
    for (int k=0; k<N; k++) {
        int tempPathToGo[N] = {MAX};
        for (int m=0; m<N; m++) {

        }

    }
    





    //2. Time to comeback - Dijkstra
    bool visited[N] = {false};
    bool stall = true;
    for (int j=0; j<N; j++) stall = stall && visited[j];
    queue<int> q;
    while !stall {

    }


}