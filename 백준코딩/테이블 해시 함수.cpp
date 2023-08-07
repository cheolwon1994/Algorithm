#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
struct info{
    int idx,colVal,keyVal;
};
struct cmp{
    bool operator()(info &a, info &b){
        if(a.colVal==b.colVal){
            return a.keyVal < b.keyVal;
        }
        return a.colVal > b.colVal;
    }
};
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = -1;
    priority_queue<info,vector<info>,cmp> pq;
    for(int i=0;i<data.size();i++)
        pq.push({i,data[i][col-1],data[i][0]});
    
    int cnt = 1;
    while(!pq.empty()){
        info ii = pq.top();
        pq.pop();
        if(row_begin<=cnt && cnt<=row_end){
            int sum = 0;
            for(int j=0;j<data[ii.idx].size();j++){
                int remain = data[ii.idx][j]%cnt;
                sum+=remain;
            }
            if(answer==-1) answer = sum;
            else answer^=sum;
        }
        cnt++;
    }
    return answer;
}
