#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <set>
using namespace std;
bool check[20][1<<17];      //해당 idx에 모은 2^idx들의 합으로 방문한 적 있는가
int answer;
vector<int> v[20];

void dfs(vector<int> info, int idx, int sheep, int wolf, int bit){
    check[idx][bit] = true;
    if(sheep <= wolf) return;
    answer = max(answer, sheep);
    
    for(int i=0;i<v[idx].size();i++){
        int next = v[idx][i];
        //현재 양, 늑대로 방문한 적 있는가
        if(check[next][bit]) continue;
        //다음 node를 방문한 적 있는가
        if((bit&(1<<next))>0){
            dfs(info, next, sheep, wolf, bit);
        }
        else{
            int nextBit = bit^(1<<next);
            int ns = (info[next] == 0) ? sheep+1 : sheep;
            int nw = (info[next] == 1) ? wolf+1 : wolf;
            dfs(info, next, ns, nw, nextBit);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    //init
    answer = 0;
    
    for(int i=0;i<edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(info, 0, 1, 0, 1<<0);
    return answer;
}
