#include <string>
#include <vector>
#include <cmath>
using namespace std;
int needEnergy[8];
int useEnergy[8];
bool check[8]={false,};
int num;
int result=0;

void dfs(int cnt, int remain){
    for(int i=0;i<num;i++){
        if(!check[i] && needEnergy[i]<=remain){
            check[i]=true;
            dfs(cnt+1,remain-useEnergy[i]);
            check[i]=false;
        }
    }
    result = max(result,cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    num = dungeons.size();
    for(int i=0;i<num;i++){
        needEnergy[i] = dungeons[i][0];
        useEnergy[i] = dungeons[i][1];
    }
    dfs(0,k);
    return answer = result;
}