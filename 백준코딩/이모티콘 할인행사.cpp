#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> v;
int maxPlus = 0, maxSum = 0;

void buyImoticon(vector<vector<int>> users, vector<int> emoticons){
    int plus=0,sum=0;
    for(int i=0;i<users.size();i++){
        int minRate = users[i][0];
        int buySum = 0;
        for(int j=0;j<v.size();j++){
            if(v[j]>=minRate)
                buySum+=(emoticons[j]*(100-v[j])/100);
        }
        if(buySum>=users[i][1]) plus++;
        else sum+=buySum;
    }
    if(plus>maxPlus){
        maxPlus = plus;
        maxSum = sum;
    }
    else if(plus==maxPlus){
        maxSum = max(maxSum,sum);
    }
    return;
}

void dfs(int idx, vector<vector<int>> users, vector<int> emoticons){
    if(idx==emoticons.size()){
        buyImoticon(users, emoticons);
        return;
    }
    for(int i=10;i<=40;i+=10){
        v.push_back(i);
        dfs(idx+1, users, emoticons);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dfs(0, users, emoticons);
    answer.push_back(maxPlus);
    answer.push_back(maxSum);
    return answer;
}
