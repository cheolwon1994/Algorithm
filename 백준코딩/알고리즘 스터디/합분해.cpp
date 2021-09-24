#include <iostream>
using namespace std;
long long arr[201][201];		//(앞의 번호)개를 사용하여 (뒤의 번호)를 만든다
long long MOD = 1000000000;

int main() {
	long long tot;
	int num;
	cin >> tot >> num;
	for (int j = 0; j <= tot; j++)
		arr[1][j] = 1;
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <= tot; j++) {
			for (int k = j; k >= 0; k--) {
				arr[i][j] += arr[i - 1][j - k];
				arr[i][j] %= MOD;
			}
		}
	}
	cout << arr[num][tot];
	system("pause");
	return 0;
}