class Solution {
    public int maxProfit(int[] prices) {
      int len = prices.length;
			int maxVal = 0;
			for(int i=0;i<len-1;i++) {
				if(prices[i]<prices[i+1])
					maxVal +=prices[i+1]-prices[i];
			}
			
			return maxVal;
    }
}
