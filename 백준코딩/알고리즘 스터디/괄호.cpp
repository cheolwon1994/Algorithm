#include <iostream>
using namespace std;

long long MOD = 1000000007, result;
long long fact[10001];

long long pow(long long val, long long idx) {
	if (idx == 0) return 1;
	else if (idx == 1) return val;
	if (idx % 2 == 0) {
		long long temp = pow(val, idx / 2);
		temp *= temp;
		temp %= MOD;
		return temp;
	}
	else {
		long long temp = pow(val, idx - 1);
		temp *= val;
		temp %= MOD;
		return temp;
	}
}

int main() {
	int test, len;
	cin >> test;
	fact[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	for (int i = 0; i < test; i++) {
		cin >> len;
		if (len % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}
		len /= 2;
		long long up = fact[2 * len];
		long long down = fact[len + 1];
		down *= fact[len];
		down %= MOD;
		result = up * pow(down, MOD - 2);
		cout << result % MOD << '\n';
	}
	system("pause");
	return 0;
}