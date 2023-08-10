#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> answer;
int maxi;
vector<int> v;

void dfs(int idx, int remain, int lionScore, int apeacheScore, vector<int> info) {
    if (idx == 11) {
        int diff = apeacheScore - lionScore;
        if (diff <=0 || diff < maxi || apeacheScore ==0) return;
        if (diff > maxi) {
            maxi = diff;
            answer = v;
        }
        else if(diff == maxi){
            bool avail = false;
            for (int i = 10; i >= 0; i--) {
                if (v[i] > answer[i]) {
                    avail = true;
                    break;
                }
                else if (v[i] == answer[i]) continue;
                else break;
            }
            if (avail) {
                answer = v;
                maxi = diff;
            }
        }
        return;
    }
    if (idx == 10) {
        v.push_back(remain);
        dfs(idx + 1, 0, lionScore, apeacheScore, info);
        v.pop_back();
    }
    else {
        for (int i = 0; i <= remain; i++) {
            v.push_back(i);
            int apeacheAdd = v[idx] > info[idx] ? 10 - idx : 0;
            int lionAdd = v[idx] <= info[idx] ? 10 - idx : 0;
            if (info[idx] == 0) lionAdd = 0;
            dfs(idx + 1, remain - i, lionScore + lionAdd, apeacheScore + apeacheAdd, info);
            v.pop_back();
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    maxi = 0;
    dfs(0, n, 0, 0, info);
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
