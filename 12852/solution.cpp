#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#define pairs pair<int,string>
#define MAX 1000001
using namespace std;

int cal_num_op(string str, char Delimiter) {
    istringstream iss(str);            
    string buffer;                  
 
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    int length = result.size();
 
    return length;
}

int main() {
    //init
    int** res_mat;
    res_mat = new int*[MAX];
    for (int m=0; m<MAX; m++) {
        res_mat[m] = new int[3];
    }
    for (int i=1; i<MAX; i++) { //0:div 3, 1:div 2, 2:sub 1
        if (i%3==0) {
            res_mat[i][0] = i/3;
        }
        else {
            res_mat[i][0] = 0;
        }
        if (i%2==0) {
            res_mat[i][1] = i/2;
        }
        else {
            res_mat[i][1] = 0;
        }
        if (i!=1) {
            res_mat[i][2] = i-1;
        }
        else {
            res_mat[i][2] = 0;
        }
    }

    int num;
    cin >> num;

    queue<pairs> q;
    q.push(pairs(num, to_string(num)));
    bool* visited = new bool[MAX];
    for (int n=0; n<MAX; n++) {
        if (n == num) {
            visited[n] = true;
        }
        else {
            visited[n] = false;
        }
    }

    int walker = q.front().first;
    while (walker!=1) {
        int div3 = res_mat[walker][0];
        int div2 = res_mat[walker][1];
        int sub1 = res_mat[walker][2];
        if ((div3!=0)&&(!visited[div3])) {
            q.push(pairs(div3, q.front().second+" "+to_string(div3)));
            visited[div3] = true;
        }
        if ((div2!=0)&&(!visited[div2])) {
            q.push(pairs(div2, q.front().second+" "+to_string(div2)));
            visited[div2] = true;
        }
        if ((sub1!=0)&&(!visited[sub1])) {
            q.push(pairs(sub1, q.front().second+" "+to_string(sub1)));
            visited[sub1] = true;
        }
        q.pop();
        walker = q.front().first;
    }
    int num_op = cal_num_op(q.front().second, ' ')-1;
    cout << num_op << endl;
    cout << q.front().second << endl;
    delete[] res_mat;
    delete[] visited;
    return 0;
}