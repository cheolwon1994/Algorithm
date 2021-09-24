#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int pre[200001];        //���� Node�� �ʿ�� �ϴ� ���: ����, ���� Node�� ���: ���, ���� ���: 0
vector<int> v[200001];
int check[200001];     //1~N��ŭ ����� ����,-1: �湮�� ������ ����Node�� ���� �湮�� ���� ���� ���, 1: �湮�� ���
int node;

bool bfs() {
	queue<int> q;
	q.push(1);
	int cnt = 1;
	check[1] = 1;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < v[cidx].size(); i++) {
			int next = v[cidx][i];
			if (check[next]>0) continue;
			else {
				if (pre[next] == 0) {
					cnt++;
					q.push(next);
					check[next] = 1;
				}
				else if (pre[next] > 0) {		//���� Node�� ���
					cnt++;
					q.push(next);
					check[next] = 1;
					//�湮 ������ ���
					if (check[pre[next]] == -1) {
						check[pre[next]] = 1;
						cnt++;
						q.push(pre[next]);
					}
				}
				else if (pre[next] < 0) {		//���� Node�� ���
					check[next] = -1;
					int post = -pre[next];
					if (check[post] == 1) {
						check[next] = 1;
						cnt++;
						q.push(next);
					}
				}
			}
		}
	}
	if (cnt == node) return true;
	return false;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    node = n;
    for(int i=1;i<=node;i++){
        pre[i]=0;
        check[i]=0;
    }
    for(int i=0;i<path.size();i++){
        int s = path[i][0];
        int e = path[i][1];
        v[s+1].push_back(e+1);
        v[e+1].push_back(s+1);
    }
    for(int i=0;i<order.size();i++){
        pre[order[i][1]+1] = -(order[i][0]+1);
        pre[order[i][0]+1] = order[i][1]+1;
    }
    if(pre[1]<0)
        answer=false;
    else
        answer = bfs();
    return answer;
}