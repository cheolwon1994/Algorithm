class Solution {
    public int majorityElement(int[] nums) {
		int maxCnt = 0;
        int maxVal = -1;
        Map<Integer,Integer> map = new HashMap<>();
        for(int val : nums){
            int mapValue = map.get(val) == null ? 0 : map.get(val);
        	map.put(val, mapValue+1);
            if(mapValue+1>maxCnt){
                maxCnt = mapValue+1;
                maxVal = val;
            }
        }
        return maxVal;
    }
}
