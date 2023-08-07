#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 987654321;

void dfs(int storey, int cnt){
    if(storey==0){
        answer = min(answer, cnt);
        return;
    }
    int remain = storey%10;
    if(remain < 5){
        dfs(storey/10,cnt+remain);
    }
    else if(remain>5){
        int q = storey/10;
        dfs(q*10+10,cnt+10-remain);
    }
    else{
        dfs(storey/10,cnt+remain);
        int q = storey/10;
        dfs(q*10+10,cnt+10-remain);
    }
}

int solution(int storey) {
    dfs(storey,0);
    return answer;
}
