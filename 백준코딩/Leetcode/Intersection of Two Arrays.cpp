class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> left,right;
        vector<int> answer;
        for(int num: nums1) left.insert(num);
        for(int num: nums2) right.insert(num);
        for(auto it = left.begin();it!=left.end();it++){
            int num = *it;
            if(right.find(num)!=right.end())
                answer.push_back(num);
        }
        return answer;
    }
};
