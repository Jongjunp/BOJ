#include <iostream>
#include <string>
#include <queue>
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
    //1. Time to go - BFS, Dijkstra
    int minPathToGo[N] = {MAX};
    queue<int> qToGo;
    




    //2. Time to comeback - BFS, Dijkstra
    bool visited[N] = {false};
    bool stall = true;
    for (int j=0; j<N; j++) stall = stall && visited[j];
    queue<int> q;
    while !stall {

    }


}