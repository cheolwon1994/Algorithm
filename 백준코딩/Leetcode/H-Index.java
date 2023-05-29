class Solution {
    public int hIndex(int[] citations) {
        int len = citations.length;
        Integer[] dup = new Integer[len];
        for (int i = 0; i < len; i++) {
        	dup[i] = citations[i];
        }
        Arrays.sort(dup, Collections.reverseOrder());
        int result = len;
        for(int i=0;i<len;i++){
            if(dup[i]<=i){
                result = i;
                break;
            }
        }
        return result;
    }
}
