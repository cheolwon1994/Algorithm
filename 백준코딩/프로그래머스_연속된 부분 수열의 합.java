class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int minLen = 1000001;
        int l=0,r=0;
        int sum=sequence[0];
        int len = sequence.length;
        while(l<=r && r<len){
            if(sum==k){
                if(r-l<minLen){
                    minLen = r-l;
                    answer[0]=l;
                    answer[1]=r;
                }
                if(l==r){
                    if(r==len-1) break;
                    else sum+=sequence[++r];
                }
                else{
                    sum-=sequence[l++];
                }
            }
            else if(sum<k){
                if(r==len-1) break;
                else sum+=sequence[++r];
            }
            else{
                if(l==r){
                    if(r==len-1) break;
                    sum=sequence[++r];
                    l++;
                }
                else{
                    sum-=sequence[l++];
                }
            }
        }
        return answer;
    }
}
