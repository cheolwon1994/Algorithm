#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=0;i<enemy.size();i++){
        int val = enemy[i];
        pq.push(val);
        n-=val;
        if(n<0){
            if(k==0){
                answer = i;
                break;
            }
            while(!pq.empty() && k>0 && n<0){
                n+=pq.top();
                k--;
                pq.pop();
            }
        }
    }
    return answer==-1 ? enemy.size() : answer;
}
