#define MAX 987654321
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct info {
	int idx;
	long long val;
};
info tmp;
int node, edge, s, e, val;
vector<info> v[101];
vector<int> rev[101];		//Node번호에서 역으로 추적하여 닿을 수 있는 Node들 check
long long dist[101];
bool cycle = false;
int previous[101];
bool visit[101] = { false, };

void bellman_ford() {
	for (int k = 1; k <= node; k++) {
		for (int i = 1; i <= node; i++) {
			int from = i;
			for (int j = 0; j < v[from].size(); j++) {
				int to = v[from][j].idx;
				int nv = v[from][j].val;
				if (dist[from]!=MAX && dist[to] > dist[from] + nv) {
					dist[to] = dist[from] + nv;
					previous[to] = from;
					if (k == node && visit[to])
						cycle = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		val *= -1;
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
		rev[e].push_back(s);
	}
	queue<int> q;
	q.push(node);
	visit[node] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	for (int i = 2; i <= node; i++)
		dist[i] = MAX;
	bellman_ford();
	if (cycle)
		cout << -1;
	else {
		vector<int> ans;
		int idx = node;
		while (1) {
			ans.push_back(idx);
			if (idx == 1)	break;
			else	idx = previous[idx];
		}
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
	}
	system("pause");
	return 0;
}