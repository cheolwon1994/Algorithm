#include <iostream>
#include <queue>
#include <string>
using namespace std;
int arr[1000][1000];
int check[1000][1000][10];
struct info {
	int x, y, wall;
};
info tmp;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, crash;
	string s;
	cin >> row >> col >> crash;
	for (int i = 0; i < row; i++) {
		cin >> s;
		for (int j = 0; j < col; j++)
			arr[i][j] = s[j] - '0';
	}
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	tmp.wall = 0;
	q.push(tmp);
	check[0][0][0] = 1;
	int result = -1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cw = q.front().wall;
		q.pop();
		if (cx == col - 1 && cy == row - 1) {
			result = check[cy][cx][cw];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row) {
				if (arr[ny][nx] == 0 && check[ny][nx][cw]==0) {
					check[ny][nx][cw] = check[cy][cx][cw] + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.wall = cw;
					q.push(tmp);
				}
				else if(arr[ny][nx]==1 && check[ny][nx][cw+1]==0 && cw<crash){
					check[ny][nx][cw + 1] = check[cy][cx][cw] + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.wall = cw + 1;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}