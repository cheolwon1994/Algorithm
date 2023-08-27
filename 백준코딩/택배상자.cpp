#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int len = order.size();
    //보조 컨테이너
    stack<int> s;
    
    for(int inputBoxNum = 1;inputBoxNum <= order.size();inputBoxNum++){
        s.push(inputBoxNum);
        while(!s.empty()){
            if(s.top() == order[answer]){
                s.pop();
                answer++;
            }
            else break;
        }
    }
    
    return answer;
}
