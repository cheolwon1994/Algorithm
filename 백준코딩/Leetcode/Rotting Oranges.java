class Solution {
    static class Info {
        int y, x;

        public Info(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    static final int dx[] = {0,1,0,-1};
    static final int dy[] = {-1,0,1,0};

    public int orangesRotting(int[][] arr) {
        int answer = 0;
        int row = arr.length;
        int col = arr[0].length;
        int fresh = 0;
        int spreadTime[][] = new int[row][col];
        Queue<Info> q = new LinkedList<>();

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                spreadTime[i][j] = -1;
                int val = arr[i][j];
                if(val > 0){
                    if(val == 1) fresh++;
                    else {
                        q.offer(new Info(i,j));
                        spreadTime[i][j] = 0;
                    }
                }
            }

        while(!q.isEmpty()){
            Info ii = q.poll();
            int cx = ii.x;
            int cy = ii.y;
            int ct = spreadTime[cy][cx];
            answer = Math.max(answer, ct);

            for(int k=0;k<4;k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx >= 0 && ny >= 0 && nx< col && ny < row && arr[ny][nx] > 0 && spreadTime[ny][nx] == -1){
                    q.offer(new Info(ny,nx));
                    spreadTime[ny][nx] = ct + 1;
                    fresh--;
                }
            }
        }

        return fresh == 0 ? answer : -1;
    }
}
