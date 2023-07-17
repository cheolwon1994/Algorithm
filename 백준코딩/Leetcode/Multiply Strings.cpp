class Solution {
public:
    string getMulByChar(char a, char b, string sum, int idx){
        int aNum = a - '0';
        int bNum = b - '0';
        int plusNum = 0;
        string ss = sum;
        if(sum.size()>idx){
            plusNum = sum[0] - '0';
            ss = sum.substr(1,sum.size());
        }
        int result = aNum*bNum+plusNum;
        return to_string(result)+ss;
    }

    string addTwoString(string a, string b){
        string answer = "";
        int alen = a.size();
        int blen = b.size();
        int diff = blen - alen;
        string toAdd = "";
        for(int k=0;k<diff;k++)
            toAdd+="0";
        if(alen < blen){
            a = toAdd+a;
        }
        else if(alen > blen){
            b = toAdd+b;
        }

        for(int i=a.size()-1;i>=0;i--){
            int aNum = a[i]-'0';
            int bNum = b[i]-'0';
            int plusNum = 0;
            string ss = answer;
            if(answer.size()>a.size()-1-i){
                plusNum = answer[0] - '0';
                ss = answer.substr(1,answer.size());
            }
            int result = aNum+bNum+plusNum;
            answer = to_string(result)+ss;
        }
        return answer;
    }

    string multiply(string num1, string num2) {
        string answer = "0";
        for(int i=num2.size()-1;i>=0;i--){
            string s = "";
            for(int j=num1.size()-1;j>=0;j--){
                s = getMulByChar(num2[i],num1[j],s,num1.size()-1-j);
            }
            for(int j=0;j<num2.size()-1-i;j++)
                s+="0";
            answer = addTwoString(answer, s);
        }

        //check if answer starts with 0
        int idx = -1;
        for(int i=0;i<answer.size();i++){
            if(answer[i]!='0'){
                idx = i;
                break;
            }
        }
        if(idx>0){
            answer = answer.substr(idx, answer.size());
        }
        //answer is consecutive zero's
        else if(idx == -1){
            answer = "0";
        }
        return answer;
    }
};
