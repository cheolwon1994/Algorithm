import java.util.*;

class Solution {
    static class Info implements Comparable<Info>{
        int y,x,val;
        public Info(int y, int x, int val){
            this.y=y;
            this.x=x;
            this.val=val;
        }

        @Override
        public int compareTo(Info o){
            return Integer.compare(this.val,o.val);
        }
    }
    static final int dx[] = {0,1,0,-1};
    static final int dy[] = {-1,0,1,0};
    static final int MAXI = 10001;
    
    public int solution(String[] board) {
        int answer = -1;
        int row = board.length;
        int col = board[0].length();
        int flag[][] = new int[row][col];
        PriorityQueue<Info> pq = new PriorityQueue<>();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char c= board[i].charAt(j);
                flag[i][j]=MAXI;
                if(c=='R'){
                    pq.offer(new Info(i,j,0));
                    flag[i][j]=0;
                }
            }
        }
        
        while(!pq.isEmpty()){
            Info info = pq.poll();
            int cx = info.x;
            int cy = info.y;
            int cv = info.val;
            char cc = board[cy].charAt(cx);
            if(cc=='G'){
                answer = cv;
                break;
            }
            for(int i=0;i<4;i++){
                int nx = cx;
                int ny = cy;
                while(true){
                    nx+=dx[i];
                    ny+=dy[i];
                    if(nx>=0 && ny>=0 && nx<col && ny<row){
                        int nc = board[ny].charAt(nx);
                        if(nc=='D'){
                            nx-=dx[i];
                            ny-=dy[i];
                            break;
                        }
                    }
                    else{
                        nx-=dx[i];
                        ny-=dy[i];
                        break;
                    }
                }
                if(flag[ny][nx]>cv+1){
                    flag[ny][nx] = cv+1;
                    pq.offer(new Info(ny,nx,cv+1));
                }
            }
        }
        return answer;
    }
}
