#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int s, e, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};
info tmp;
int node, edge, s, e, val;
int par[1001];
int find_parent(int x) {
	if (par[x] == x) return x;
	return par[x] = find_parent(par[x]);
}

void make_union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) par[b] = a;
	else if (a > b) par[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= node; i++)
		par[i] = i;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e >> val;
		tmp.s = s;
		tmp.e = e;
		tmp.val = val;
		pq.push(tmp);
	}
	long long result = 0;
	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;
		int cv = pq.top().val;
		pq.pop();
		int ps = find_parent(cs);
		int pe = find_parent(ce);
		if (ps == pe) continue;
		make_union(cs, ce);
		result += cv;
	}
	cout << result;
	system("pause");
	return 0;
}