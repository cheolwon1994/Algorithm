#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int minsik[4];
int other[50][4];
vector<string> v;

int cal(int idx) {
	int temp;
	int t[4];
	t[0] = minsik[0] + other[idx][0];
	t[1] = minsik[1] + other[idx][1];
	t[2] = minsik[2] + other[idx][2];
	t[3] = minsik[3] + other[idx][3];
	temp = (t[0] + t[1])*(t[0] + t[2])*(t[0] + t[3])*(t[1] + t[2])*(t[1] + t[3])*(t[2] + t[3]);
	return temp % 100;
}

int main() {
	int maxi = -1, num;
	string result = "", s, str;
	cin >> str >> num;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == 'L') minsik[0]++;
		else if (c == 'O') minsik[1]++;
		else if (c == 'V') minsik[2]++;
		else if (c == 'E') minsik[3]++;
	}
	for (int i = 0; i < num; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			char c = v[i][j];
			if (c == 'L') other[i][0]++;
			else if (c == 'O') other[i][1]++;
			else if (c == 'V') other[i][2]++;
			else if (c == 'E') other[i][3]++;
		}
		int t_result = cal(i);
		if (t_result > maxi) {
			maxi = t_result;
			result = v[i];
		}
	}
	cout << result;
	system("pause");
	return 0;
}