#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
int maxi = 10000001;
struct info{
    int idx,val;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    int mainSummit = 0, minIntensity=maxi;
    //init
    vector<info> node[50001];
    for(int i=0;i<paths.size();i++){
        int from = paths[i][0];
        int to = paths[i][1];
        int val = paths[i][2];
        node[from].push_back({to,val});
        node[to].push_back({from,val});
    }
    set<int> s;
    int mini[50001];
    for(int i=0;i<summits.size();i++)
        s.insert(summits[i]);
    for(int i=0;i<=n;i++)
        mini[i] = maxi;
    
    for(int i=0;i<gates.size();i++){
        queue<info> q;
        int curIdx = gates[i];
        mini[curIdx]=0;
        for(int j=0;j<node[curIdx].size();j++){
            int next = node[curIdx][j].idx;
            int nv = node[curIdx][j].val;
            if(mini[next]>nv){
                mini[next]=nv;
                q.push({next,nv});
            }
        }
        
        while(!q.empty()){
            info ii = q.front();
            q.pop();
            int cidx = ii.idx;
            int cv = ii.val;
            //봉우리
            if(s.find(cidx)!=s.end()){
                if(minIntensity>cv){
                    minIntensity = cv;
                    mainSummit = cidx;
                }
                else if(minIntensity==cv){
                    mainSummit = min(mainSummit, cidx);
                }
                continue;
            }
            for(int k=0;k<node[cidx].size();k++){
                int next = node[cidx][k].idx;
                int nv = max(node[cidx][k].val,cv);
                if(mini[next]>nv){
                    mini[next]=nv;
                    q.push({next,nv});
                }
            }
        }
    }
    answer.push_back(mainSummit);
    answer.push_back(minIntensity);
    return answer;
}
