#include <iostream>
using namespace std;
int main() {
    int makuwa,dir,h;
    int num_makuwa = 0;
    int height = 0;
    cin >> makuwa;
    for (int i=0; i<6; i++) {
        cin >> dir >> h;
        if (dir==1) {
            num_makuwa -= h*makuwa*height;
        }
        else if (dir==2) {
            num_makuwa += h*makuwa*height;
        }
        else if (dir==3) {
            height -= h;
        }
        else {
            height += h;
        }
    }
    cout << num_makuwa << endl;
}