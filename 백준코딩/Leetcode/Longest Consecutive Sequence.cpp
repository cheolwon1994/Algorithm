class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int answer = 1;
        map<int, int> m;        //need, start from

        for(int num : nums){
            if(m.find(num)==m.end()) m[num+1] = num;
            else {
                m[num+1] = m[num];
            }
        }
        int from, to;
        for(auto it = m.begin();it!=m.end();it++){
            if(it == m.begin()){
                from = it->second;
                to = it->first;
            }
            else{
                int left = it->second;
                int right = it->first;
                if(from <= left && left<=to) to = right;
                else if(left < from) from = left;
                else{
                    answer = max(answer, to - from);
                    from = left;
                    to = right;
                }
            }
        }
        answer = max(answer, to - from);
        return answer;
    }
};
