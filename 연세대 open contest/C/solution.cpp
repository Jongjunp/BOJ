#include <iostream>
using namespace std;
long long xorSum(long long n) {
	long long m = n % 4;
	if (m == 0) return n;
	if (m == 1) return 1;
	if (m == 2) return n + 1;
	return 0;
}
long long xorIntervalSum(long long left, long long right) {
	return xorSum(left - 1) ^ xorSum(right);
}
int main() {
    long long A,B;
    cin >> A >> B;
    cout << xorIntervalSum(A,B) << endl;
}