#define MAX 987654321
#include <iostream>
#include <queue>
using namespace std;
struct info {
	int y, x;
};
int arr[1000][1000];
int check[1000][1000];
int row, col, sx, sy, val;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void init() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			check[i][j] = MAX;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;

	init();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sx = j;
				sy = i;
			}
		}
	queue<info> q;
	q.push({ sy,sx });
	check[sy][sx] = 0;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < col && ny<row && check[ny][nx]>check[cy][cx] + 1 && arr[ny][nx] != 0) {
				check[ny][nx] = check[cy][cx] + 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int val = check[i][j];
			if (val == MAX) {
				if (arr[i][j]) val = -1;
				else val = 0;
			}
			cout << val << " ";
		}
		cout << '\n';
	}
	return 0;
}