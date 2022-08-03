#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
const int MAX = 200001;
int parent[MAX] = {0};
int group_size[MAX] = {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

void union_op(int x, int y) {
    int parent_x = find_op(x);
    int parent_y = find_op(y);
    if (parent_x==parent_y) return;
    if (group_size[parent_x]>group_size[parent_y]) {
        parent[parent_y] = parent_x;
        group_size[parent_x] += group_size[parent_y];
        group_size[parent_y] = 0;
    }
    else {
        parent[parent_x] = parent_y;
        group_size[parent_y] += group_size[parent_x];
        group_size[parent_x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T,F;
    cin >> T;
    for (int i=0; i<T; i++) {
        unordered_map<string, int> dict;
        for (int i=0; i<MAX; i++) {
            parent[i] = i;
            group_size[i] = 1;
        }
        cin >> F;
        string friend1, friend2;
        int id = 0;
        for (int j=0; j<F; j++) {
            cin >> friend1 >> friend2;
            int id1, id2;
            unordered_map<string, int>::iterator finditer1 = dict.find(friend1);
            if (finditer1!=dict.end()) {
                id1 = finditer1->second;
            }
            else {
                dict.insert(unordered_map<string, int>::value_type(friend1, id));
                id1 = id;
                id++;
            }
            unordered_map<string, int>::iterator finditer2 = dict.find(friend2);
            if (finditer2!=dict.end()) {
                id2 = finditer2->second;
            }
            else {
                dict.insert(unordered_map<string, int>::value_type(friend2, id));
                id2 = id;
                id++;
            }
            union_op(id1,id2);
            cout << group_size[find_op(id1)] << "\n";
        }
    }
}