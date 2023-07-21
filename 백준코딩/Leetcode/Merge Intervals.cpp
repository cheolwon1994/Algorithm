class Solution {
    struct info{
        int start, end;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            if(a.start==b.start){
                return a.end < b.end;
            }
            return a.start > b.start;
        };
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<info,vector<info>,cmp> pq;
        vector<vector<int>> answer;

        for(int i=0;i<intervals.size();i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            pq.push({s,e});
        }

        int from = pq.top().start,to = pq.top().end;
        pq.pop();
        while(!pq.empty()){
            info ii = pq.top();
            pq.pop();
            int cs = ii.start;
            int ce = ii.end;
            //continuous
            if(cs<=to){
                to = max(to,ce);
            }
            //need interval
            else{
                answer.push_back({from,to});
                from = cs;
                to = ce;
            }
        }
        answer.push_back({from,to});

        return answer;
    }
};
