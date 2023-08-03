class Solution {
    struct info{
        int idx,color;
    };
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int len = graph.size();
      int flag[100] = {false,};
      for(int i=0;i<len;i++){
        if(graph[i].size() && flag[i]==0){
            queue<info> q;
            q.push({i,1});
            flag[i] = 1;

            while(!q.empty()){
                info ii = q.front();
                q.pop();
                int cidx = ii.idx;
                int cc = ii.color;
                for(int i=0;i<graph[cidx].size();i++){
                    int next = graph[cidx][i];
                    if(!flag[next]){
                        flag[next] = 3-cc;
                        q.push({next,3-cc});
                    }
                    else{
                        if(flag[next]+cc!=3) return false;
                    }
                }
            }
        }
      }
      return true;
    }
};
