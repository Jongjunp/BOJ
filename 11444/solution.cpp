#include <iostream>
using namespace std;
const int DIVIDER = 1000000007;
long *mat_cal(long first, long second, long third){
    long new_first = (((first*first)%DIVIDER)+((second*third)%DIVIDER))%DIVIDER;
    long new_second = (2*((second*third)%DIVIDER))%DIVIDER;
    long new_third = (2*((first*third)%DIVIDER))%DIVIDER;
    return [new_first, new_second, new_third];
}

int main(){
    long nth;
    cin >> nth;
    
    
}