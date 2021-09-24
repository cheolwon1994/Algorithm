#include <vector>
#include <algorithm>
using namespace std;
vector<int> s;
int jmp;

bool cal(int val){
    int idx = -1;
	for (int i = 0; i < jmp; i++) {
		if (s[i] >= val) {
			idx = i;
			break;
		}
	}
	if (idx == -1) return false;
    while(idx < s.size()){
        bool avail=false;
        for(int i=1;i<=jmp;i++){
            if(idx+i==s.size()){        //���� �����ϴ� ���
                avail=true;
                idx+=i;
                break;
            }
            if(s[idx+i]>=val){          //��� ���� �ִ� ���
                idx+=i;
                avail=true;
                break;
            }
        }
        if(!avail) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    s = stones;
    jmp = k;
    int low=0,high=200000000,mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(cal(mid)){       //mid��ŭ �ǳ� �� �ִ�
            low = mid+1;
            answer = mid;
        }
        else{               //mid��ŭ �ǳ� �� ����
            high = mid-1;       
        }
    }
    return answer;
}