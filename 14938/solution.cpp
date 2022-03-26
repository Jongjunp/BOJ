#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int maxItemNum(int field_arr[][101], int items_arr[], int start_region, int num_region, int search_range) {
    queue< pair<int,int> > region_queue;
    bool visited_list[101] = {false};
    int max_items = 0;
    max_items += items_arr[start_region];
    visited_list[start_region] = true; 
    region_queue.push(pair<int,int>(start_region,0));
    while (!region_queue.empty()) {
        pair<int,int> region = region_queue.front();
        region_queue.pop();
        for (int m=1; m<=num_region; m++) {
            if ((field_arr[region.first][m]!=0)
                 && (!visited_list[m]) 
                 && (region.second+field_arr[region.first][m]<=search_range)) {
                visited_list[m] = true;
                max_items += items_arr[m];
                region_queue.push(pair<int,int>(m,region.second+field_arr[region.first][m]));
            }
        }
    }
    return max_items;
}

int main() {
    int numRegion, searchRange, numPath;
    cin >> numRegion >> searchRange >> numPath;

    int itemsInRegion[101] = {0};
    for (int i=1; i<=numRegion; i++) cin >> itemsInRegion[i];

    int field[101][101] = {0};
    for (int j=1; j<=numPath; j++) {
        int start,end,pathLength;
        cin >> start >> end >> pathLength;
        field[start][end] = pathLength;
        field[end][start] = pathLength;
    }

    int maxItems = 0;
    for (int k=1; k<=numRegion; k++) {
        int tempMax = maxItemNum(field, itemsInRegion, k, numRegion, searchRange);
        if (maxItems < tempMax) {
            maxItems = tempMax;
        }
    }
    cout << maxItems << endl;
}