class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;

        vector<int> node[2000];
        int conn[2000] = {0,};
        for(int i=0;i<numCourses;i++){
            node[i].clear();
            conn[i] = 0;
        }

        for(int i=0;i<prerequisites.size();i++){
            int pre = prerequisites[i][1];
            int post = prerequisites[i][0];
            node[pre].push_back(post);
            conn[post]++;
        }

        int cnt = 0;
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(conn[i]==0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int cidx = q.front();
            q.pop();
            for(int i=0;i<node[cidx].size();i++){
                int next = node[cidx][i];
                if(--conn[next]==0){
                    q.push(next);
                    cnt++;
                }
            }
        }

        return numCourses == cnt;
    }
};
