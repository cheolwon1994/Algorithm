#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int three2ten(string str){
    int val=0;
    int mul=1;
    for(int i=str.size()-1;i>=0;i--){
        int a = str[i]-'0';
        val+=a*mul;
        mul*=3;
    }
    return val;
}

int ten2three(int n){
    stack<char> s;
    while(n){
        int val = n%3;
        s.push(val+'0');
        n/=3;
    }
    string str = "";
    while(!s.empty()){
        str=s.top()+str;
        s.pop();
    }
    return three2ten(str);
}

int solution(int n) {
    int answer = 0;
    return answer = ten2three(n);
}
