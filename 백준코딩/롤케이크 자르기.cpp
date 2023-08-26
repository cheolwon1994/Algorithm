#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    map<int, int> left, right;    //토핑 종류, 수
    int answer = 0;
    int leftCnt = 0, rightCnt;
    for(int num: topping)
        right[num]+=1;
    rightCnt = right.size();
    
    for(int num: topping){
        //fill left map
        if(left.find(num)==left.end()){
            left[num] = 1;
            leftCnt++;
        }
        else{
            left[num]+=1;
        }
        
        //check right map
        if(--right[num] == 0) rightCnt--;
        
        if(leftCnt == rightCnt) answer++;
    }
    
    return answer;
}
