class Solution {
public:
    struct info{
        int num, freq;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            return a.freq < b.freq;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;    //num, freq
        vector<int> answer;

        for(int num: nums)
            m[num] += 1;
        priority_queue<info,vector<info>,cmp> pq;

        for(auto it = m.begin();it!=m.end();it++){
            pq.push({it->first, it->second});
        }

        while(k-- > 0){
            answer.push_back(pq.top().num);
            pq.pop();
        }
        return answer;
    }
};
