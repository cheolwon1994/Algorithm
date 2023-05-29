class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int cnt[] = new int[len];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);

        while(!q.isEmpty()){
            int idx = q.poll();
            if(idx==len-1) break;
            int curCnt = cnt[idx];
            int val = nums[idx];

            for(int i=1;i<=val;i++){
                int next = idx+i;
                if(next>=len) break;
                if(cnt[next]==0){
                    cnt[next]=curCnt+1;
                    q.offer(next);
                }
            }
        }

        return cnt[len-1];
    }
}
