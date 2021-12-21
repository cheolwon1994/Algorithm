#define MAX 9876543210
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct info{
    int idx,odd;
    long long val;
};
struct cmp{
    bool operator()(info &a, info &b){
        return a.val > b.val;
    }
};
vector<info> v[4001];
int node,edge,a,b,result=0;
long long val;
long long dist[4001][3];       //[][0]: 늑대 짝, [][1]: 늑대 홀, [][2]: 여우

void dijkstra(int flag){
    priority_queue<info,vector<info>,cmp> pq;
    if(flag==0) pq.push({1,0,0});
    else pq.push({1,0,0});
    while(!pq.empty()){
        int cidx = pq.top().idx;
        int codd = pq.top().odd;
        long long cval = pq.top().val;
        pq.pop();
        if(dist[cidx][flag+codd]<cval) continue;
        for(int i=0;i<v[cidx].size();i++){
            int next = v[cidx][i].idx;
            
            long long nv = v[cidx][i].val;
            if(flag==0 && codd==1)  nv*=4;
            else if(flag==2) nv*=2;
            
            int nextOdd = 0;
            if(flag==0) nextOdd = codd==1 ? 0 : 1;
            if(dist[next][flag+nextOdd]>cval+nv){
                dist[next][flag+nextOdd]=cval+nv;
                pq.push({next,nextOdd,cval+nv});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>node>>edge;
    //초기화
    for(int i=1;i<=node;i++)
        for(int j=0;j<4;j++)
            dist[i][j]=MAX;
    
    for(int i=0;i<edge;i++){
        cin>>a>>b>>val;
        v[a].push_back({b,0,val});
        v[b].push_back({a,0,val});
    }
    for(int i=0;i<4;i+=2)
        dijkstra(i);
    
    for(int i=2;i<=node;i++){
        long long wolfMin = min(dist[i][0], dist[i][1]);
        long long foxMin = dist[i][2];
        if(wolfMin>foxMin) result++;
    }
    cout<<result;
    return 0;
}
