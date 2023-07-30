#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
struct info{
    int idx,cnt;
};
struct cmp{
    bool operator()(info &a, info &b){
        return a.idx < b.idx;
    }
};

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    priority_queue<info,vector<info>,cmp> deliver, takeBack;
    for(int i=0;i<deliveries.size();i++){
        int val = deliveries[i];
        if(val==0) continue;
        deliver.push({i+1,val});
    }
    for(int i=0;i<pickups.size();i++){
        int val = pickups[i];
        if(val==0) continue;
        takeBack.push({i+1,val});
    }
    
    while(!deliver.empty() || !takeBack.empty()){
        int curLoc = 0;
        //택배를 싣는다
        int loadNum = 0;
        while(!deliver.empty()){
            info ii = deliver.top();
            deliver.pop();
            int curCnt = ii.cnt;
            if(curCnt+loadNum>cap){
                deliver.push({ii.idx,curCnt-(cap-loadNum)});
                loadNum = cap;
            }
            else loadNum+=curCnt;
            curLoc = curLoc==0 ? ii.idx : curLoc; 
            if(loadNum==cap) break;
        }
        //위치 이동
        answer += curLoc;
        
        //수거한다
        loadNum = 0;
        int farLoc = 0;
        while(!takeBack.empty()){
            info ii = takeBack.top();
            takeBack.pop();
            int curCnt = ii.cnt;
            if(curCnt+loadNum>cap){
                int remain = curCnt - (cap-loadNum);
                takeBack.push({ii.idx,remain});
                loadNum = cap;
            }
            else loadNum+=curCnt;
            farLoc = farLoc==0 ? ii.idx : farLoc; 
            if(loadNum==cap) break;
        }
        //위치 이동
        answer += abs(curLoc-farLoc);
        
        //물품 가지고 창고로 다시 이동
        answer+=farLoc;
    }
    
    return answer;
}
