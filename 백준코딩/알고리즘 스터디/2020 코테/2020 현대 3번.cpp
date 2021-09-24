#include<vector>
#include <algorithm>
using namespace std;
int arr[4][4],dup[4][4],temp[4][4];
bool check[4][4];
vector<int> order;
int num=4,answer;

void mv(int dir) {
	bool check[4][4] = { false, };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			dup[i][j] = 0;
	if (dir == 0) {
		for (int j = 0; j < 4; j++) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				if (temp[i][j] == 0)
					continue;
				else {
					dup[cnt][j] = temp[i][j];
					if (cnt > 0 && dup[cnt - 1][j] == dup[cnt][j] && !check[cnt - 1][j]) {
						dup[cnt - 1][j] *= 2;
						dup[cnt][j] = 0;
						check[cnt - 1][j] = true;
					}
					else
						cnt++;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 4; i++) {
			int cnt = 3;
			for (int j = 3; j >= 0; j--) {
				if (arr[i][j] == 0) continue;
				else {
					dup[i][cnt] = temp[i][j];
					if (cnt != 3 && dup[i][cnt + 1] == dup[i][cnt] && !check[i][cnt + 1]) {
						dup[i][cnt + 1] *= 2;
						dup[i][cnt] = 0;
						check[i][cnt + 1] = true;
					}
					else
						cnt--;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < 4; j++) {
			int cnt = 3;
			for (int i = 3; i >= 0; i--) {
				if (temp[i][j] == 0)		continue;
				else {
					dup[cnt][j] = temp[i][j];
					if (cnt != num - 1 && dup[cnt + 1][j] == dup[cnt][j] && !check[cnt + 1][j]) {
						dup[cnt + 1][j] *= 2;
						dup[cnt][j] = 0;
						check[cnt + 1][j] = true;
					}
					else
						cnt--;
				}
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < 4; i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (temp[i][j] == 0) continue;
				else {
					dup[i][cnt] = temp[i][j];
					if (cnt != 0 && dup[i][cnt - 1] == dup[i][cnt] && !check[i][cnt - 1]) {
						dup[i][cnt - 1] *= 2;
						dup[i][cnt] = 0;
						check[i][cnt - 1] = true;
					}
					else
						cnt++;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			temp[i][j] = dup[i][j];
}

void dfs(int idx) {
	if (idx == 5) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				temp[i][j] = arr[i][j];
			
		for (int i = 0; i < order.size(); i++)
			mv(order[i]);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				answer = max(answer, temp[i][j]);
		return;
	}
	for (int i = 0; i < 4; i++) {
		order.push_back(i);
		dfs(idx + 1);
		order.pop_back();
	}
}

int solution(vector<vector<int> > board)
{
	answer = -1;    
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++)
            arr[i][j]=board[i][j];
    dfs(0);
	return answer;
}