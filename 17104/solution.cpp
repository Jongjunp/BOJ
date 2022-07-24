#include <iostream>
#include <cmath>
using namespace std;
const int LIMIT = 1000001;
bool isprime[LIMIT] = {false};

void sifter() {
    for (int i=0; i<LIMIT; i++) {
        isprime[i] = true;
    }
    for (int i=2; i<(int)sqrt((float)LIMIT); i++) {
        if (isprime[i]) {
            for (int j=2*i; j<LIMIT; j+=i){
                isprime[j] = false;
            }
        }
    }
}

int main() {
    int test_num;
    scanf("%d", &test_num);
    for (int i=0; i<test_num; i++) {
        int num;
        scanf("%d", &num);
        int partition_cnt = 0;
        for (int k=2; k<(num/2)+1; k++) {
            int res = num-k;
            if (check[k] && check[res] && res>=k){
                partition_cnt += 1;
            }
        }
        printf("%d\n", partition_cnt);
    }
}