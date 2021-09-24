#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdlib.h>
using namespace std;
vector<long long> v;
vector<char> op;
int order[3];           //+,-,* 순서
bool check[3]={false,};
long long result=0;

void cal() {
	deque <long long> dq, dq2;
	deque <char> cd, cd2;
	dq.push_back(v[0]);
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+' && order[0] == 0) {      //현재 +가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll += v[i+1];
			dq.push_back(ll);
		}
		else if (op[i] == '-' && order[1] == 0) {     //현재 -가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll -= v[i+1];
			dq.push_back(ll);
		}
		else if (op[i] == '*' && order[2] == 0) {     //현재 *가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll *= v[i+1];
			dq.push_back(ll);
		}
		else {
			dq.push_back(v[i+1]);
			cd.push_back(op[i]);
		}
	}
	dq2.push_back(dq[0]);
	for (int i = 0; i < cd.size(); i++) {
		if (cd[i] == '+' && order[0] == 1) {      //현재 +가 가장 높은 우선순위
			long long ll = dq2[dq2.size() - 1];
			dq2.pop_back();
			ll += dq[i + 1];
			dq2.push_back(ll);
		}
		else if (cd[i] == '-' && order[1] == 1) {     //현재 -가 가장 높은 우선순위
			long long ll = dq2[dq2.size() - 1];
			dq2.pop_back();
			ll -= dq[i + 1];
			dq2.push_back(ll);
		}
		else if (cd[i] == '*' && order[2] == 1) {     //현재 *가 가장 높은 우선순위
			long long ll = dq2[dq2.size() - 1];
			dq2.pop_back();
			ll *= dq[i + 1];
			dq2.push_back(ll);
		}
		else {
			dq2.push_back(dq[i + 1]);
			cd2.push_back(cd[i]);
		}
	}
	dq.clear();
	dq.push_back(dq2[0]);
	for (int i = 0; i < cd2.size(); i++) {
		if (cd2[i] == '+' && order[0] == 2) {      //현재 +가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll += dq2[i + 1];
			dq.push_back(ll);
		}
		else if (cd2[i] == '-' && order[1] == 2) {     //현재 -가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll -= dq2[i + 1];
			dq.push_back(ll);
		}
		else if (cd2[i] == '*' && order[2] == 2) {     //현재 *가 가장 높은 우선순위
			long long ll = dq[dq.size() - 1];
			dq.pop_back();
			ll *= dq2[i + 1];
			dq.push_back(ll);
		}
		else {
			dq.push_back(dq[i + 1]);
			cd.push_back(cd[i]);
		}
	}
	long long t_result = dq[0];
	result = max(result, abs(t_result));
}

void dfs(int idx){
    if(idx==3){
        cal();
        return;
    }
    for(int i=0;i<3;i++){
        if(!check[i]){
            check[i]=true;
            order[idx]=i;
            dfs(idx+1);
            order[idx]=0;
            check[i]=false;
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    int idx=0;
    for(int i=0;i<=expression.size();i++){
        if(i==expression.size()){
            string s = expression.substr(idx,i-idx);
            long long ll = atoi(s.c_str());
            v.push_back(ll);
        }
        if(expression[i]=='-' || expression[i]=='*' || expression[i]=='+'){
            string s = expression.substr(idx,i-idx);
            idx=i+1;
            long long ll = atoi(s.c_str());
            v.push_back(ll);
            op.push_back(expression[i]);
        }
    }
    dfs(0);
    answer = result;
    return answer;
}