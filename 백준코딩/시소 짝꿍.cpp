#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int len = weights.size();
    set<int> s;
    map<int, int> m, balance;
    for(int i=0;i<len;i++){
        int val = weights[i];
        s.insert(val);
        if(m.find(val)!=m.end()) m[val]+=1;
        else m[val]=1;
    }
    
    //중복된 경우 따로 계산
    for(auto it = m.begin();it!=m.end();it++){
        int val = it->second;
        if(val>1){
            answer += (long long)val*(val-1)/2;
        }
    }
    
    for(auto it = s.begin();it!=s.end();it++){
        int weight = *it;
        int cnt = m[weight];
        
        for(int k=2;k<5;k++){
            int nw = weight*k;
            if(balance.find(nw)==balance.end()){
                balance[nw]=cnt;
            }
            else{
                answer+=((long long)balance[nw]*cnt);
                balance[nw]+=cnt;
            }
        }
    }
    return answer;
}
