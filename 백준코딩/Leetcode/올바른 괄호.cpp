#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string str)
{
    stack<char> s;
    
    for(int i=0;i<str.size();i++){
        char c = str[i];
        if(c == '(') s.push(c);
        // ')'
        else{
            if(s.empty()) return false;
            s.pop();
        }
    }
    
    return !s.empty() ? false : true;
}
