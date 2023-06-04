import java.util.*;

class Solution {
    static class Info implements Comparable<Info>{
        int from, to;

        public Info(int from,int to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public int compareTo(Info o) {
            if(this.from==o.from) {
                return Integer.compare(this.to, o.to);
            }
            return Integer.compare(this.from, o.from);
        }		
    }
    
    public int solution(int[][] targets) {
        int answer = 1;
	    PriorityQueue<Info> pq = new PriorityQueue<>();
	    for(int i=0;i<targets.length;i++) {
	    	pq.offer(new Info(targets[i][0], targets[i][1]));
        }
	    Info start = pq.poll();
	    int curFrom = start.from;
        int curTo = start.to;
        while(!pq.isEmpty()) {
	        Info ii = pq.poll();
	    	if(curTo>ii.from) {		//범위에 포함되는 경우
	    		curFrom = ii.from;
        		curTo = Math.min(curTo,ii.to);
            }
	        else {
	    		curFrom = ii.from;
	    		curTo = ii.to;
        		answer++;
            }
	    }
	    return answer;
    }
}
