#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
int num;
string ip[1000];
int ans[2][4];

string int2string(int val) {
	string s = "";
	for (int i = 0; i < 8; i++) {
		int p = val % 2;
		if (p == 0) s = "0" + s;
		else s = "1" + s;
		val /= 2;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	string str,s1;
	for (int i = 0; i < num; i++) {
		cin >> str;
		istringstream ss(str);
		int idx = 0;
		while (getline(ss, s1, '.')) {
			ip[i] += int2string(stoi(s1));
		}
	}
	int idx = 32;
	for (int i = 0; i < 32; i++) {
		for (int j = 1; j < num; j++) {
			if (ip[0][i] != ip[j][i]) {
				idx = i;
				break;
			}
		}
		if (idx < 32) break;
	}
	int fir = 0, sec = 0;
	for (int i = 0; i < 32; i++) {
		if (i % 8 == 0 && i != 0) {
			ans[0][(i / 8) - 1] = fir;
			ans[1][(i / 8) - 1] = sec;
			fir = 0;
			sec = 0;
		}
		fir *= 2;
		sec *= 2;
		if (i < idx) {
			int c = ip[0][i] - '0';
			fir += c;
			sec += 1;
		}
	}
	ans[0][3] = fir;
	ans[1][3] = sec;
	cout << ans[0][0] << "." << ans[0][1] << "." << ans[0][2] << "." << ans[0][3] << '\n';
	cout << ans[1][0] << "." << ans[1][1] << "." << ans[1][2] << "." << ans[1][3] << '\n';
	return 0;
}