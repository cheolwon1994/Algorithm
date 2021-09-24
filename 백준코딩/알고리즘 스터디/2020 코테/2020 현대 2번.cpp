#define MAX 987654321
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct info{
  int x,y,val;  
};
info tmp;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int check[601][601];

vector<vector<int>> solution(int N, vector<vector<int>> bus_stop) {
    vector<vector<int>> answer;
    int num = N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            check[i][j]=MAX;
    queue<info> q;
    for(int i=0;i<bus_stop.size();i++){
        int cy = bus_stop[i][0];
        int cx = bus_stop[i][1];
        check[cy][cx]=0;
        tmp.x=cx;
        tmp.y=cy;
        tmp.val=0;
        q.push(tmp);
    }
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cv = q.front().val;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>0 && ny>0 && nx<=num && ny<=num && check[ny][nx]>cv+1){
                check[ny][nx]=cv+1;
                tmp.x=nx;
                tmp.y=ny;
                tmp.val = cv+1;
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= num; i++) {
		vector<int> ans;
		for (int j = 1; j <= num; j++) {
			ans.push_back(check[i][j]);
		}
		answer.push_back(ans);
	}  
    return answer;
}