#include <vector>
#include <queue>
using namespace std;
struct info{
    int x,y;
};
info tmp;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
bool check[100][100];
int solution(vector<vector<int> > maps){
    int answer =0;
    for(int i=0;i<maps.size();i++)
        for(int j=0;j<maps[i].size();j++)
            check[i][j]=false;
    int row = maps.size();
    int col = maps[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(maps[i][j]==1 && !check[i][j]){
                queue<info> q;
                tmp.x=j;
                tmp.y=i;
                check[i][j]=true;
                q.push(tmp);
                while(!q.empty()){
                    int cx = q.front().x;
                    int cy = q.front().y;
                    q.pop();
                    int val=4;
                    for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < col && ny < row && maps[ny][nx] == 1) {
							if (!check[ny][nx]) {
								check[ny][nx] = true;
								val--;
								tmp.x = nx;
								tmp.y = ny;
								q.push(tmp);
							}
							else
								val--;
						}
					}
					answer += val;
                }
            }
        }
    }
    return answer;
}