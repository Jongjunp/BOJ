#include <iostream>
using namespace std;
const int DEFAULT = 100;
int main() {
    char point_list[52];
    cin >> point_list;
    int cow_cross_count = 0;
    int cow_fst_list[26];
    for (int i=0; i<26; i++) {
        cow_fst_list[i] = DEFAULT;
    }
    int cow_snd_list[26];
    for (int i=0; i<26; i++) {
        cow_snd_list[i] = DEFAULT;
    }
    for (int i=0; i<52; i++) {
        int cow = point_list[i]-'A';
        if (cow_fst_list[cow]==DEFAULT){
            cow_fst_list[cow] = i;
        }
        else {
            cow_snd_list[cow] = i;
        }
    }
    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            if ((cow_fst_list[i]<cow_fst_list[j] && cow_snd_list[i]>cow_fst_list[j] && cow_snd_list[i]<cow_snd_list[j] && j!=i)
                ||(cow_fst_list[i]<cow_snd_list[j] && cow_snd_list[i]>cow_snd_list[j] && cow_fst_list[i]>cow_fst_list[j] && j!=i)){
                    cow_cross_count += 1;
                }
        }
    }
    int answer = cow_cross_count/2;
    cout << answer << endl;
}