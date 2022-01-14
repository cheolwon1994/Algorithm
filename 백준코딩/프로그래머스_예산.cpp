#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0,idx=0;
    sort(d.begin(),d.end());
    while(idx<d.size()){
        if(d[idx]<=budget){
            budget-=d[idx++];
            answer++;
        }
        else break;
    }
    return answer;
}
