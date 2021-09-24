#define MAX 987654321
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct info{
    int x,y,dir;
};
info tmp;
int arr[25][25];
int check[25][25][4];       //y,x,어떤 방향에서 왔는가
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int row,col;

void bfs() {
	queue<info> q;
	tmp.x = 0;
	tmp.y = 0;
	for (int i = 0; i < 4; i++) {
		check[0][0][i] = 0;
		tmp.dir = i;      //현재 진행중인 방향
		q.push(tmp);
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dir;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == 0) {
				if (cd == i && check[ny][nx][cd] > check[cy][cx][cd] + 100) {      //같은 방향으로 진행중
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = i;
					q.push(tmp);
					check[ny][nx][i] = check[cy][cx][cd] + 100;
				}
				else if (cd != i && check[ny][nx][i] > check[cy][cx][cd] + 600) {         //다른방향
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = i;
					q.push(tmp);
					check[ny][nx][i] = check[cy][cx][cd] + 600;
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
    int answer = MAX;
    row = board.size();
    col = board[0].size();
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            arr[i][j]=board[i][j];
            for(int k=0;k<4;k++)
                check[i][j][k]=MAX;
        }
    }
    bfs();
    for(int i=0;i<4;i++)
        answer = min(answer,check[row-1][col-1][i]);
    return answer;
}