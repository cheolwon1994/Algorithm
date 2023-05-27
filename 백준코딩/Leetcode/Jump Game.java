class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        if(len==1) return true;
        
        boolean flag[] = new boolean[len];
        boolean finish = false;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        flag[0] = true;

        while(!q.isEmpty()){
            int curIdx = q.poll();
            int val = nums[curIdx];
            for(int i=1;i<=val;i++){
                int next = curIdx+i;
                if(next>=len) continue;
                if(next==len-1){
                    finish=true;
                    break;
                }
                if(!flag[next]){
                    flag[next]=true;
                    q.offer(next);
                }
            }
            if(finish) break;
        }
        return finish;
    }
}
