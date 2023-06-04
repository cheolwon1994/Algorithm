import java.util.*;

class Solution {
    public long solution(int r1, int r2) {
		long answer = 0;
		for (int i = 1; i <= r2; i++) {
			int smallY = (int) Math.ceil(Math.sqrt((double)r1 * r1 - (double)i * i));
			int bigY = (int) Math.floor(Math.sqrt((double)r2 * r2 - (double)i * i));
			answer += 4*(bigY-smallY+1);
		}
		return answer;
    }
}
