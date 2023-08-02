#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> m;
    int ty = stoi(today.substr(0,4));
    int tm = stoi(today.substr(5,2));
    int td = stoi(today.substr(8));
    
    for(int i=0;i<terms.size();i++){
        char c = terms[i][0];
        int month = stoi(terms[i].substr(2));
        m[c] = month;
    }
    
    for(int i=0;i<privacies.size();i++){
        int year = stoi(privacies[i].substr(0,4));
        int month = stoi(privacies[i].substr(5,2));
        int day = stoi(privacies[i].substr(8,2));
        
        char c = privacies[i][11];
        month+=m[c];
        
        if(day==1){
            day = 28;
            month--;
        }
        else day--;
        while(month>12){
            month-=12;
            year++;
        }
        if(ty>year || (ty==year)&&(tm>month) || (ty==year)&&(tm==month)&&(td>day)) answer.push_back(i+1);
    }
    return answer;
}
