#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int pre[200001];        //선행 Node를 필요로 하는 경우: 음수, 선행 Node인 경우: 양수, 없는 경우: 0
vector<int> v[200001];
int check[200001];     //1~N만큼 사용할 예정,-1: 방문을 했지만 선행Node가 아직 방문이 되지 않은 경우, 1: 방문한 경우
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
				else if (pre[next] > 0) {		//선행 Node인 경우
					cnt++;
					q.push(next);
					check[next] = 1;
					//방문 가능한 경우
					if (check[pre[next]] == -1) {
						check[pre[next]] = 1;
						cnt++;
						q.push(pre[next]);
					}
				}
				else if (pre[next] < 0) {		//후행 Node인 경우
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