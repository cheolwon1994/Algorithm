#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int arr[100][100];
int dup[100][100];
int dx[2] = { -1,1 };
int move(int y,int x, int dir) {
	int cx = x;
	while (1) {
		if (arr[y][cx + dx[dir]] == 1 && cx + dx[dir]>=0 && cx + dx[dir]<100) 
			cx = cx + dx[dir];	
		else
			break;
	}
	return cx;
}

int main() {
	int test, dest;
	for (int t = 1; t <= 10; t++) {
		cin >> test;
		vector<int> v;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				if (i == 0 && arr[i][j]==1) {
					v.push_back(j);
				}
				if (arr[i][j] == 2)
					dest = j;
			}
		}
		int cx, cy, idx;
		for (int i = 0; i < v.size(); i++) {
			cx = v[i];
			idx = v[i];
			for (int j = 0; j < 100; j++) {
				cy = j;
				if (cx == 0) {		//왼쪽 끝에 위치
					if (arr[cy][cx + 1] == 1) {
						cx = move(cy, cx, 1);		//오른쪽으로 이동
					}
					else 
						continue;					
				}
				else if (cx == 99) {		//오른쪽 끝에 위치
					if (arr[cy][cx - 1] == 1)
						cx = move(cy, cx, 0);
					else 
						continue;
				}
				else if (cx > 0 && cx < 99) {
					if (arr[cy][cx - 1] == 1)		//왼쪽으로 이동
						cx = move(cy, cx, 0);
					else if (arr[cy][cx + 1] == 1)		//오른쪽으로 이동
						cx = move(cy, cx, 1);
					else 
						continue;
				}
			}
			if (cx == dest)
				break;
		}
		cout << "#" << t << " " << idx << endl;
	}
	system("pause");
	return 0;
}