class Solution {
public:
    int maxVowels(string str, int k) {
        //init
       int cnt = 0;
       int len = str.size();
       set<char> s;
       s.insert('a');
       s.insert('e');
       s.insert('i');
       s.insert('o');
       s.insert('u');

       for(int i=0;i<k;i++){
           char c = str[i];
           if(s.contains(c)) cnt++;
       }
       int answer = cnt;

       int l = 0, r = k-1;
        while(r < len){
            if(r + 1 < len){
                if(s.contains(str[l++])) cnt--;
                if(s.contains(str[++r])) cnt++;
                answer = max(answer, cnt);
            }
            else break;
        }

        return answer;
    }
};
