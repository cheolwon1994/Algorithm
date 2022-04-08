#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

bool reportResult[1000][1000];
map<string,int> m;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int num=0;
    for(string str: id_list)
        m[str]=num++;
    
    string str;
    for(int i=0;i<report.size();i++){
        istringstream ss(report[i]);
        vector<string> v;
        while (getline(ss, str, ' ')) {
            v.push_back(str);
        }
        reportResult[m[v[0]]][m[v[1]]] = true;
    }
    vector<int> reported;
    for(int j=0;j<num;j++){
        int sum = 0;
        for(int i=0;i<num;i++)
            sum+=reportResult[i][j];
        if(sum>=k) reported.push_back(j);
    }
    for(int i=0;i<num;i++){
        int sum=0;
        for(int j=0;j<reported.size();j++)
            if(reportResult[i][reported[j]])
                sum++;
        answer.push_back(sum);
    }
    return answer;
}
