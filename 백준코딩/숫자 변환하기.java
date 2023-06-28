import java.util.*;

class Solution {
    static class Info{
        int val,cnt;
        public Info(int val, int cnt){
            this.val=val;
            this.cnt=cnt;
        }
    }
    static final int MAXI = 1000001;
    
    public int solution(int x, int y, int n) {
        int answer = MAXI;
        int flag[] = new int[MAXI];
        for(int i=x;i<=y;i++)
            flag[i]=MAXI;
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(x,0));
        
        while(!q.isEmpty()){
            Info ii = q.poll();
            if(ii.cnt >= answer) break;
            int cv = ii.val;
            int cc = ii.cnt;
            if(cv==y){
                answer = Math.min(answer,cc);
                break;
            }
            int nv = cv+n;
            if(nv<=y && flag[nv]>cc+1){
                flag[nv]=cc+1;
                q.offer(new Info(nv,cc+1));
            }
            nv = cv*2;
            if(nv<=y && flag[nv]>cc+1){
                flag[nv]=cc+1;
                q.offer(new Info(nv,cc+1));
            }
            nv = cv*3;
            if(nv<=y && flag[nv]>cc+1){
                flag[nv]=cc+1;
                q.offer(new Info(nv,cc+1));
            }
        }
        
        return answer == MAXI ? -1 : answer;
    }
}
