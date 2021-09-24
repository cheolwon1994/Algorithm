#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int conn[1001];
vector<int> v[1001];
vector<int> ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, num, val, s, e;
	cin >> node >> num;
	queue<int> q;
	for (int i = 0; i < num; i++) {
		cin >> val;
		if (val == 0) continue;
		cin >> s;
		if (val == 1) continue;
		for (int j = 0; j < val - 1; j++) {
			cin >> e;
			v[s].push_back(e);
			conn[e]++;
			s = e;
		}
	}
	for (int i = 1; i <= node; i++) 
		if (conn[i] == 0) 
			q.push(i);	
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		ans.push_back(cidx);
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			conn[next]--;
			if (conn[next] == 0) 
				q.push(next);			
		}
	}
	if (ans.size() != node) cout << 0;
	else {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	}	
	system("pause");
	return 0;
}