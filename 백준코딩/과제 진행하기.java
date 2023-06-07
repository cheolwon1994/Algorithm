import java.util.*;

class Solution {
    static class Info implements Comparable<Info> {
		String name;
		int arriveTime, leftTime;

		public Info(String name, int arriveTime, int leftTime) {
			this.name = name;
			this.arriveTime = arriveTime;
			this.leftTime = leftTime;
		}

		@Override
		public int compareTo(Info o) {
			return Integer.compare(this.arriveTime, o.arriveTime);
		}
	}
	
	static class Info2 implements Comparable<Info2> {
		String name;
		int arriveTime, leftTime;

		public Info2(String name, int arriveTime, int leftTime) {
			this.name = name;
			this.arriveTime = arriveTime;
			this.leftTime = leftTime;
		}

		@Override
		public int compareTo(Info2 o) {
			return Integer.compare(o.arriveTime, this.arriveTime);
		}
	}
    
    public String[] solution(String[][] plans) {
        int len = plans.length;
        String[] answer = new String[len];
        PriorityQueue<Info> startPlan = new PriorityQueue<>();
        PriorityQueue<Info2> pausedPlan = new PriorityQueue<>();
        for(int i=0;i<len;i++) {
        	StringTokenizer st = new StringTokenizer(plans[i][1], ":");
        	int hour = Integer.parseInt(st.nextToken());
        	int min = Integer.parseInt(st.nextToken());
        	startPlan.offer(new Info(plans[i][0], hour*60+min, Integer.parseInt(plans[i][2])));
        }
        
        int cnt=0;
        
        while(!startPlan.isEmpty()) {
        	Info curPlan = startPlan.poll();
        	
        	if(startPlan.isEmpty()) {
        		answer[cnt++]=curPlan.name;
        		while(!pausedPlan.isEmpty()) {
        			answer[cnt++] = pausedPlan.poll().name;
        		}
        		break;
        	}
        	
        	Info nextPlan = startPlan.peek();
        	int nextPlanStartTime = nextPlan.arriveTime;
        	int curPlanFinTime = curPlan.arriveTime+curPlan.leftTime;
        	if(curPlanFinTime<=nextPlanStartTime) {
        		answer[cnt++] = curPlan.name;
                if(curPlanFinTime==nextPlanStartTime)   continue;
                    
        		if(!pausedPlan.isEmpty()) {
        			Info2 temp = pausedPlan.poll();
        			startPlan.offer(new Info(temp.name, curPlanFinTime, temp.leftTime));
        		}
        	}
        	else {		// 변경 필요
        		int remainTime = curPlanFinTime-nextPlanStartTime;
        		pausedPlan.offer(new Info2(curPlan.name, nextPlanStartTime, remainTime));
        	}
        }
        
        return answer;
    }
}
