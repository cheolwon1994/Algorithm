import java.util.*;

class Solution {
    static class Info{
        int idx,val;
        public Info(int idx, int val){
            this.idx=idx;
            this.val=val;
        }
    }
    
    public int[] solution(int[] numbers) {
        int len = numbers.length;
        Stack<Info> s = new Stack<>();
        int[] answer = new int[len];
        for(int i=0;i<len;i++){
            int curNum = numbers[i];
            while(!s.isEmpty()){
                Info ii = s.peek();
                if(ii.val>=curNum) break;
                else{
                    answer[ii.idx]=curNum;
                    s.pop();
                }
            }
            s.add(new Info(i,curNum));
        }
        while(!s.isEmpty()){
            Info ii = s.pop();
            answer[ii.idx] = -1;
        }
        return answer;
    }
}
