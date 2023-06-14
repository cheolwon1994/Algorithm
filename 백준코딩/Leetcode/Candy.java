# 1
import java.util.*;

class Solution {
    static class Info implements Comparable<Info> {
        int val,idx;
        public Info(int idx, int val){
            this.idx = idx;
            this.val = val;
        }

        @Override
        public int compareTo(Info o){
            return Integer.compare(this.val, o.val);
        }
    }
    
    public int candy(int[] ratings) {
        int len = ratings.length;
        int[] flag = new int[len];
        PriorityQueue<Info> pq = new PriorityQueue<>();

        for(int i=0;i<len;i++){
            pq.offer(new Info(i, ratings[i]));
        }
        
        int sum = 0;
        while(!pq.isEmpty()){
            Info ii = pq.poll();
            int cidx = ii.idx;
            int cv = ii.val;
            int idx = cidx;
            int flagVal = flag[cidx];
            //check left
            if(cidx>0 && ratings[cidx]>ratings[cidx-1]){
                idx = cidx-1;
                flagVal = flag[cidx-1];
            }
            //check right
            if(cidx<len-1 && ratings[cidx]>ratings[cidx+1]){
                if(flagVal<flag[cidx+1]){
                    idx = cidx+1;
                    flagVal = flag[cidx+1];
                }
            }
            flag[cidx] = flagVal+1;
            sum+=(flagVal+1);
        }

        return sum;
    }
}

# 2
import java.util.*;

class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        int[] flag = new int[len];
        Arrays.fill(flag,1);
       
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1]){
                flag[i]=flag[i-1]+1;
            }
        }
        for(int i=len-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && flag[i]<=flag[i+1]){
                flag[i] = flag[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<len;i++)
            sum+=flag[i];
        return sum;
    }
}
