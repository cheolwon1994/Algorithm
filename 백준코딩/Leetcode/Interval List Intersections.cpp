class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int l = 0,r = 0;
        while(l<firstList.size() && r<secondList.size()){
            int fs = firstList[l][0];
            int fe = firstList[l][1];
            int ss = secondList[r][0];
            int se = secondList[r][1];

            int start = fs < ss ? ss : fs;
            int end = fe < se ? fe : se;

            //if have intersection
            if(start<=end){
                //add to answer
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                answer.push_back(temp);
            }
            //move to next index which finishes first
            if(fe<se) l++;
            else if(fe>se) r++;
            //if both finish at same time, elminate both elements since new start is bigger than end
            else{
                l++;
                r++;
            }
        }

        return answer;
    }
};
