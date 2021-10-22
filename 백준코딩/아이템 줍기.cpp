#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct info{
    int y,x,val,dir;
};
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={-1,0,1,0,-1,1,1,-1};
int arr[101][101];
bool check[8]={false,};
int num=0,fx,fy,totLen,halfLen;

void dfs(int y, int x, int dir, int dist, int ey, int ex) {
	if (y == fy && x == fx) {
		totLen = dist/2;
		return;
	}
	if (y == ey && x == ex)  halfLen = dist/2;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && ny > 0 && nx <= num && ny <= num && arr[ny][nx] == 1)
			cnt++;
	}
	if (cnt == 2) dir = (dir + 1) % 4;     //꼭지점
	else if (cnt == 4)  dir = (dir + 3) % 4;   //교차로
	dfs(y + dy[dir]*2, x + dx[dir]*2, dir, dist + 2, ey, ex);
}

void findPathByRightHand(int sy, int sx, int ey, int ex){
    int cnt=0,dir,dirTot=0;
    for(int i=0;i<4;i++){
        int nx = sx+dx[i];
        int ny = sy+dy[i];
        if(nx>0 && ny>0 && nx<=num && ny<=num && arr[ny][nx]==1){
            cnt++;
            check[i]=true;
            dirTot+=i;
        }
    }
    if(cnt==2){     //꼭지점
        if(check[0] && check[1]) dir=0;
        else if(check[1] && check[2]) dir=1;
        else if(check[2] && check[3]) dir=2;
        else dir=3;
    }
    else if(cnt==3){        //한 변의 중간(아래 문자는 Check가 true인곳 표시)
        if(dirTot==3) dir=0;        //ㅏ
        else if(dirTot==6) dir=1;   //ㅜ
        else if(dirTot==5) dir=2;   //ㅓ
        else dir=3;                 //ㅗ
    }
    else{       //두 교점의 교차지점    +
        int idx;
        //빈곳 찾기
        for(int i=4;i<8;i++){
            int nx = sx+dx[i];
            int ny = sy+dy[i];
            if(nx>0 && ny>0 && nx<=num && ny<=num && arr[ny][nx]==0){
                idx=i;
                break;
            } 
        }
        if(idx==4) dir=1;
        else if(idx==5) dir=2;
        else if(idx==6) dir=3;
        else dir=0;
    }
    dfs(sy+dy[dir]*2,sx+dx[dir]*2,dir,2,ey,ex);
}

int solution(vector<vector<int>> rectangle, int sx, int sy, int ex, int ey) {
    int answer = 0;
	sx *= 2;
	sy *= 2;
	ex *= 2;
	ey *= 2;
	fy = sy;
	fx = sx;
	for (int i = 0; i < rectangle.size(); i++) {
		int lx = rectangle[i][0] * 2;
		int ly = rectangle[i][1] * 2;
		int rx = rectangle[i][2] * 2;
		int ry = rectangle[i][3] * 2;
		num = max(num, rx);
		num = max(num, ry);
		for (int y = ly; y <= ry; y++)
			for (int x = lx; x <= rx; x++)
				arr[y][x] = 1;
	}
	findPathByRightHand(sy, sx, ey, ex);
    return answer = min(halfLen,totLen-halfLen);
}