class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefixSum[101];
        int answer = 0;
        prefixSum[0] = 0;
        
        for(int i=0;i<gain.size();i++){
            int val = gain[i];
            prefixSum[i+1] = prefixSum[i] + val;
            answer = max(answer, prefixSum[i+1]);
        }
        return answer;
    }
};
