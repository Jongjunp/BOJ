#include <iostream>
#include <cstdlib>
using namespace std;

long long gcd (long long a, long long b) {
    while (true) {
		long long c = a % b;
		if (c == 0) return b;
		a = b;
		b = c;
	}
}

int main() {
    int logpair;
    cin >> logpair;

    long long r_i_1 = 0;
    long long lower_bound = 0;
    long long temp_answer = 1;
    bool flag = true;
    for (int i=0; i<logpair; i++) {
        long long a_i, b_i;
        scanf("%lld %lld", &a_i, &b_i);
        if ((a_i < 0)&&(lower_bound < b_i)) {
            lower_bound = b_i;
        }
        long long obj_num;
        if (a_i > 0) {
            if (r_i_1 + a_i != b_i) {
                cout << -1 << endl;
                return 0;
            }
            obj_num = a_i;
        }
        else {
            if (r_i_1 + a_i >= 0) {
                if (r_i_1 + a_i != b_i) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            obj_num = abs(a_i+r_i_1-b_i);
        }
        if ((r_i_1 + a_i < 0) && flag) {
            temp_answer = obj_num;
            flag = false;
        }
        else {
            if ((obj_num != 0) && (r_i_1 + a_i < 0)) {
                temp_answer = gcd(max(obj_num, temp_answer),min(obj_num, temp_answer));
            }
        }
        r_i_1 = b_i;
    }
    long long answer = -1;
    for (int j=1; j*j<=temp_answer; j++) {
        if (temp_answer%j==0) {
            if (j > lower_bound) {
                answer = j;
                break;
            }
            else if (temp_answer/j > lower_bound) {
                answer = temp_answer/j;
                continue;
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }
    cout << answer << endl;
    return 0;
}