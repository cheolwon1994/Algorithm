#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int preNum = -1;
    for(int num: arr){
        if(preNum == num) continue;
        answer.push_back(num);
        preNum = num;
    }

    return answer;
}
