class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;    //alien language order
        for(int i=0;i<order.size();i++){
            char c = order[i];
            m[c] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            string first = words[i];
            string second = words[i+1];
            int fidx=0,sidx=0;
            bool inOrder = false;
            while(fidx<first.size() && sidx<second.size()){
                char fc = first[fidx];
                char sc = second[sidx];
                int frank = m[fc];
                int srank = m[sc];
                if(frank<srank){
                    inOrder = true;
                    break;
                }
                else if(frank==srank){
                    fidx++;
                    sidx++;
                }
                else return false;
            }
            //had same letter unitl size of second
            if(!inOrder && sidx<first.size()) return false;
        }
        return true;
    }
};
