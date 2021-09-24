#define MAX 1000000007
#include <iostream>
using namespace std;
int limit, need_time;
long long dp[10001];

int main() {
	cin >> limit >> need_time;
	for (int i = 0; i < need_time; i++)
		dp[i] = 1;
	for (int i = need_time; i <= limit; i++) 
		dp[i] = (dp[i - need_time] + dp[i - 1]) % MAX;
	cout << dp[limit];
	system("pause");
	return 0;
}