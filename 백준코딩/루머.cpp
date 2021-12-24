#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
	int idx, val, peopleNum;
};
vector<int> v[200001];
int rumorTime[200001];		//루머를 믿는 시간
int nearPeople[200001];		//주변에 루머 믿는 사람 수
int num, val, startMember;

void init() {
	for (int i = 1; i <= num; i++)
		rumorTime[i] = -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	init();

	for (int t = 1; t <= num; t++) {
		while (1) {
			cin >> val;
			if (val == 0) break;
			v[t].push_back(val);
		}
	}
	cin >> startMember;
	queue<info> q;
	for (int i = 0; i < startMember; i++) {
		cin >> val;
		q.push({ val,0,0 });
	}
	while (!q.empty()) {
		int cidx = q.front().idx;
		int cv = q.front().val;
		int cnum = q.front().peopleNum;		//당시에 주변에 루머 믿었던 사람 수
		q.pop();
		if (rumorTime[cidx] > -1) continue;		//이미 진행된 경우		
		if (cv>0 && v[cidx].size() > 2 * cnum) continue;		//주변사람 중 반 이상 루머를 믿지 않는 경우
		rumorTime[cidx] = cv;
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			nearPeople[next]++;
			if (rumorTime[next] > -1) continue;
			q.push({ next,cv + 1,nearPeople[next] });
		}
	}

	for (int i = 1; i <= num; i++)
		cout << rumorTime[i] << " ";
	return 0;
}