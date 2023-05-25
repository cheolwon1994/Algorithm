class Solution {
    public int maxProfit(int[] prices) {
				int len = prices.length;
				int maxVal = 0;
				int[] highestVal = new int[len];
				
				for(int i=len-1;i>=0;i--) {
					int val = prices[i];
					highestVal[i]=val;
					if(i==len-1) continue;
					if(val<highestVal[i+1]) {
						maxVal = Math.max(maxVal, highestVal[i+1]-val);
						highestVal[i] = highestVal[i+1];
					}
				}
				
				return maxVal;
		}
}
