#define MAXI 987654321
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct info{
    int idx, val;
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> node(n+1);   //간선 정보
    vector<int> dist(n+1);           //dest부터 각 source 까지의 거리
    
    for(int i=0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        dist[i] = MAXI;
    
    queue<info> q;
    q.push({destination, 0});
    dist[destination] = 0;
    
    while(!q.empty()){
        info ii = q.front();
        q.pop();
        int cidx = ii.idx;
        int cv = ii.val;
        
        for(int i=0;i<node[cidx].size();i++){
            int next = node[cidx][i];
            if(dist[next] > cv + 1){
                dist[next] = cv + 1;
                q.push({next, cv+1});
            }
        }
    }
    
    for(int i=0;i<sources.size();i++){
        int val = dist[sources[i]] == MAXI ? -1 : dist[sources[i]];
        answer.push_back(val);
    }
    return answer;
}
