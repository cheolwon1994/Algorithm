import java.util.*;

class Solution {
    static class Info implements Comparable<Info> {
        int start,end;
        public Info(int start, int end){
            this.start=start;
            this.end=end;
        }
        
        @Override
        public int compareTo(Info o) {
        	if(this.start== o.start) {
        		return Integer.compare(this.end,o.end);
        	}
        	return Integer.compare(this.start, o.start);
        }
    }
	
	static class Info2 implements Comparable<Info2> {
        int start,end;
        public Info2(int start, int end){
            this.start=start;
            this.end=end;
        }
        
        @Override
        public int compareTo(Info2 o) {
        	return Integer.compare(this.end, o.end);
        }
    }
    
    public int solution(String[][] book_time) {
        int answer = 0;
        int len = book_time.length;
        PriorityQueue<Info> pq = new PriorityQueue<>();
        for(int i=0;i<len;i++){
            String[] str = book_time[i];
            StringTokenizer st = new StringTokenizer(str[0],":");
            int startHour = Integer.parseInt(st.nextToken());
            int startMin = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(str[1],":");
            int endHour = Integer.parseInt(st.nextToken());
            int endMin = Integer.parseInt(st.nextToken());
            pq.offer(new Info(startHour*60+startMin, endHour*60+endMin));
        }
        
        PriorityQueue<Info2> usingRooms = new PriorityQueue<>();
        while(!pq.isEmpty()) {
        	Info ii = pq.poll();
        	while(!usingRooms.isEmpty()) {
        		Info2 fastestCheckout = usingRooms.peek();
        		if(fastestCheckout.end + 10 <=ii.start) usingRooms.poll();
        		else break;
        	}
        	usingRooms.offer(new Info2(ii.start,ii.end));
        	answer = Math.max(answer, usingRooms.size());
        }
        return answer;
    }
}
