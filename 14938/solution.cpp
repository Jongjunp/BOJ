#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int INF = 1000000;

int maxItemNum(int field_arr[][101], int items_arr[], int start_region, int num_region, int search_range) {
    queue< pair<int,int> > region_queue;
    int path_len_list[101];
    for (int r=0; r<101; r++) {
        path_len_list[r] = INF;
    }

    path_len_list[start_region] = 0;
    region_queue.push(pair<int,int>(start_region,0));
    while (!region_queue.empty()) {
        pair<int,int> region = region_queue.front();
        for (int m=1; m <= num_region; m++) {
            if ((field_arr[region.first][m]!=0)
                 && (path_len_list[m] > (region.second+field_arr[region.first][m]))) {
                path_len_list[m] = region.second+field_arr[region.first][m];
                region_queue.push(pair<int,int>(m,region.second+field_arr[region.first][m]));
            }
        }
        region_queue.pop();
    }

    int max_item_value = 0;
    for (int l=1; l<=num_region; l++) {
        if (path_len_list[l] <= search_range) {
            max_item_value += items_arr[l];
        }
    }
    return max_item_value;
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