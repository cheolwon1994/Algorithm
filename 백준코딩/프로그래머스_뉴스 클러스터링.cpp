#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> m[2];
set<string> s;

void init(string str, int flag){
    for(int i=0;i<str.size();i++){
        string ss = str.substr(i,2);
        bool avail=true;
        string temp = "";
        for(int j=0;j<2;j++){
            char c = toupper(ss[j]);
            if('A'<=c && c<='Z')  temp+=c;
            else{
                avail=false;
                break;
            }
        }
        if(avail){
            if(m[flag][temp]==0) m[flag][temp]=1;
            else m[flag][temp] = m[flag][temp]+1;
            s.insert(temp);
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    init(str1,0);
    init(str2,1);
    //모두 공집합
    if(m[0].empty() && m[1].empty()) return 65536;
    long long up = 0,down=0;
    
    for(auto it = s.begin();it!=s.end();it++){
        string str = *it;
        int a = m[0][str];
        int b = m[1][str];
        int mini = min(a,b);
        int maxi = max(a,b);
        up+=mini;
        down+=maxi;
    }
    return up*65536/down;
}
