#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    struct info{
        int idx,height;
    };
public:
    int trap(vector<int>& height) {
        int rightReachIndex[20001],leftReachIndex[20001];
        int answer = 0;
        int idx = 0;
        int len = height.size();
        stack<info> s;
        for(int i=0;i<len;i++){
            rightReachIndex[i] = -1;
            leftReachIndex[i] = -1;
        }
        //right
        for(int i=0;i<len;i++){
            int val = height[i];
            while(!s.empty()){
                int sHeight = s.top().height;
                if(sHeight>val) break;
                else{
                    rightReachIndex[s.top().idx] = i;
                    s.pop();
                }
            }
            s.push({i, val});
        }

        while(idx < len){
            int nextIdx =rightReachIndex[idx];
            if(nextIdx==-1){
                idx++;
                continue;
            }
            for(int i=idx+1;i<nextIdx;i++){
                answer+= (height[idx]-height[i]);
                height[i]=height[idx];
            }
            idx = nextIdx;
        }

        //left
        idx = len-1;
        for(int i=len-1;i>=0;i--){
            int val = height[i];
            while(!s.empty()){
                int sHeight = s.top().height;
                if(sHeight>=val) break;
                else{
                    leftReachIndex[s.top().idx] = i;
                    s.pop();
                }
            }
            s.push({i, val});
        }

        while(idx >=0){
            int nextIdx = leftReachIndex[idx];
            if(nextIdx==-1){
                idx--;
                continue;
            }
            for(int i=idx-1;i>nextIdx;i--){
                answer += (height[idx]-height[i]);
                height[i]=height[idx];
            }
            idx = nextIdx;
        }
        return answer;
    }
};
