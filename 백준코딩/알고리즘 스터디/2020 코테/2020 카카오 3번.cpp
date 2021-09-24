#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int check[100000];
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	map<string, int> m;
    map<string, int> :: iterator it;
	int cnt = 0,l=0,r=0;
	for (int i = 0; i < gems.size(); i++) {
		string ss = gems[i];
		if (m.find(ss) == m.end())      //존재x
			m[ss] = ++cnt;		
	}
    int idx=1,min_len=gems.size();
    it = m.find(gems[0]);
	check[it->second]++;
    int tot=1;
    while(l<=r && r!=gems.size()){      
        if(tot==cnt){
            //길이가 더 짧을 경우
            if(min_len > r-l+1){
                min_len = r-l+1;
                idx=l+1;
            }
            if(r==l){     
                r++;
                if (r == gems.size())
					break;
                it = m.find(gems[r]);
                if(check[it->second]==0)
                    tot++;               
                check[it->second]++;                                
            }     
            else{
                it = m.find(gems[l]);
                check[it->second]--;
                if(check[it->second]==0)
                    tot--;                
                l++;                
            }      
        }
        else{
            r++;
            if (r == gems.size())
				break;
            it = m.find(gems[r]);
            if(check[it->second]==0)
                tot++;               
            check[it->second]++;     
        }
    }
    answer.push_back(idx);
    answer.push_back(idx+min_len-1);
    return answer;
}