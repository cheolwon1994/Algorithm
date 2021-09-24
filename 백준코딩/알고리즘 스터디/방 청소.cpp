#include <iostream>
using namespace std;
int par[300001];
bool visit[300001] = { false, };

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

//a�� �θ� b�� �δ�
void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a != b)
		par[a] = b;
	cout << "LADICA\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l, a, b;
	cin >> n >> l;
	for (int i = 1; i <= l; i++)
		par[i] = i;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (!visit[a]) {		//a�� ���� �� �ִ� ���
			visit[a] = true;
			make_union(a, b);
		}
		else if (!visit[b]) {		//a�� ����å�� b�� ���� �� �ִ� ���
			visit[b] = true;
			make_union(b, a);			
		}
		else if (!visit[find_par(a)]) {		//3. a,b�� ���� ���� �� ������ ã�� ���
			int idx = find_par(a);
			visit[idx] = true;
			make_union(a, b);
		}
		else if (!visit[find_par(b)]) {		//4. a,b�� ���� ���� �� ������ ã�� ���
			int idx = find_par(b);
			visit[idx] = true;
			make_union(b, a);
		}
		else 
			cout << "SMECE\n";		
	}
	system("pause");
	return 0;
}