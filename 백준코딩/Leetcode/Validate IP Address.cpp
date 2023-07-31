class Solution {
public:
    string validIPAddress(string queryIP) {
        string answer[3] = {"IPv4", "IPv6", "Neither"};
        int dotCnt = 0,colonCnt=0;
        string s="";
        int len = queryIP.size();
        vector<string> v;
        for(int i=0;i<len;i++){
            char c = queryIP[i];
            if(c==':'){
                v.push_back(s);
                s="";
                colonCnt++;
            }
            else if(c=='.'){
                v.push_back(s);
                s="";
                dotCnt++;
            }
            else{
                if('0'<=c && c<='9' || 'a'<=c && c<='f' || 'A'<=c && c<='F') s+=c;
                //when wrong alpha is received
                else return answer[2];
            }
        }
        v.push_back(s);
        //when both received
        if(dotCnt && colonCnt) return answer[2];

        //check strings
        bool isIP6 = colonCnt ? true : false;
        //check if enough cnt
        if(!isIP6 && dotCnt!=3) return answer[2];
        else if(isIP6 && colonCnt!=7) return answer[2];

        for(int i=0;i<v.size();i++){
            s = v[i];
            if(!isIP6){
                //check if s length is between 1~4
                if(s.size()>4 || s.size()<1) return answer[2];

                string stringNum = "";
                for(int i=0;i<s.size();i++){
                    char c = s[i];
                    if('0'<=c && c<='9') stringNum+=c;
                    else return answer[2];
                }

                int num = stoi(stringNum);
                //check if num is 0~255
                if(0>num || num>255) return answer[2];
                //check containing leading zeros
                stringNum = to_string(num);
                if(stringNum.size()!=s.size()) return answer[2];
            }
            //IPv6
            else{
                //check if s length is between 1~4
                if(s.size()>4 || s.size()<1) return answer[2];
            }
        }

        return answer[isIP6];
    }
};
