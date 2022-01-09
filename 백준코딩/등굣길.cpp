#define MAX 1000
#define MOD 1000000007
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    set<int> s;
    for(int i=0;i<puddles.size();i++){
        int val = puddles[i][0]+puddles[i][1]*MAX;
        s.insert(val);
    }
    for(int i=1;i<=m;i++){
        int val = MAX+i;
        if(s.find(val)!=s.end()) break;      //웅덩이
        arr[1][i]=1;
    }
    for(int j=1;j<=n;j++){
        int val = j*MAX+1;
        if(s.find(val)!=s.end()) break;      //웅덩이
        arr[j][1]=1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            int val = i*MAX+j;
            if(s.find(val)!=s.end()) continue;      //웅덩이
            arr[i][j] = (arr[i-1][j]+arr[i][j-1])%MOD;
        }
    }
    return arr[n][m];
}